#pragma once
#include <iostream>
#include <random>
using namespace std;


namespace spisok {
	struct node {
		int _val;
		node* _left;
		node* _right;
		node(int val) { _val = val; _left = nullptr; _right = nullptr; }
		node(int val, node* left, node* right) { _val = val; _left = left; _right = right; }
		~node() {}
	};

	class tree {
	private:
		node* _top;
	public:
		size_t _len;
		tree() { _top = nullptr; _len = 0; }

		tree(const int* data, size_t len) {
			_top = nullptr;
			for (int i = 0; i < len; i++) {
				this->inseart(data[i]);
			}
			_len = len;
		}

		tree(const tree& t) {
			_top = copy(t._top);
			_len = t._len;
		}

		node* copy(node* top) {
			if (top == nullptr) return nullptr;
			else {
				node* temp = new node(top->_val);
				temp->_left = copy(top->_left);
				temp->_right = copy(top->_right);
				return temp;
			}
		}

		~tree() {
			remove_nodes(_top);
		}

		void remove_nodes(node* top) {
			if (top == nullptr) {
				return;
			}
			remove_nodes(top->_left);
			remove_nodes(top->_right);
			delete top;
		}


		bool inseart(int key) { return helping_inseart(key, _top); }

		bool helping_inseart(int key, node*& top) {
			if (top == nullptr) {
				top = new node(key);
				return true;
			}
			if (top->_val == key) return false;
			if (top->_val > key) helping_inseart(key, top->_left);
			else helping_inseart(key, top->_right);
		}

		bool contains(int key) { return helping_contains(key, _top); }

		bool helping_contains(int key, node* top) {
			if (top == nullptr) return false;
			if (top->_val == key) return true;
			return (helping_contains(key, top->_left) || helping_contains(key, top->_right));
		}

		bool erase(int val) { return helping_erase(val, _top); }

		bool helping_erase(int val, node*& top) {
			if (top == nullptr) {
				return false;
			}
			if (val < top->_val) { return helping_erase(val, top->_left); }
			else if (val > top->_val) { return helping_erase(val, top->_right); }
			else {
				if (top->_left == nullptr) {
					node* temp = top->_right;
					delete top;
					top = temp;
				}
				else if (top->_right == nullptr) {
					node* temp = top->_left;
					delete top;
					top = temp;
				}
				else {
					node* temp = top->_right;
					while (temp->_left) {
						temp = temp->_left;
					}
					top->_val = temp->_val;
					helping_erase(temp->_val, top->_right);
				}
				return false;
			}

		}

		void print() {
			cout << _top->_val << " ";
			helping_print(_top->_left);
			helping_print(_top->_right);
		}

		void helping_print(node* top) {
			if (top != nullptr) {
				helping_print(top->_left);
				cout << top->_val << " ";
				helping_print(top->_right);
			}
		}


	};
	 
	vector<int> no_replys(vector<int> orig) {
		int len = orig.size();
		tree t, copies;
		vector<int> no_copies;
		int c = 0;
		for (int i = 0; i < len; i++) if (!(t.inseart(orig[i])) && t.contains(orig[i])) copies.inseart(orig[i]);
		for (int i = 0; i < len; i++) if (!(copies.contains(orig[i]))) no_copies.push_back(orig[i]);
		return no_copies;
	}


};
