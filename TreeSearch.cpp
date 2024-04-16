#pragma once
#include <iostream>
#include <random>
using namespace std;


namespace spisok {
	struct node {
		int _val;
		Node* _left;
		Node* _right;
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

		bool inseart(int key, node* top) {
			if (top == nullptr) {
				top = new node(key);
				return true;
			}
			if (top->_val)
		}
	}
}
