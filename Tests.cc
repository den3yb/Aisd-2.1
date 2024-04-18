#include "TreeSearch.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <fstream>


using namespace std;
using namespace spisok;

TEST(treetests, construct_inseart) {
	int* array = new int[12] {9, 12, 8, 4, 5, 6, 7, 3, 1, 10, 11, 2};
	tree s(array, 12);
	s.inseart(44);
	s.print();
}

TEST(treetests, construct_contains) {
	int* array = new int[12] {9, 12, 8, 4, 5, 6, 7, 3, 1, 10, 11, 2};
	tree s(array, 12);
	cout << s.contains(4);
	cout << s.contains(44);
	
}

TEST(treetests, construct_erase) {
	int* array = new int[12] {9, 12, 8, 4, 5, 6, 7, 3, 1, 10, 11, 2};
	tree s(array, 12);
	s.erase(4);
	s.print();
}

TEST(treetests, copy) {
	int* array = new int[12] {9, 12, 8, 4, 5, 6, 7, 3, 1, 10, 11, 2};
	tree s(array, 12);
	tree t(s);
	t.print();
}

TEST(treetests, GetNoCopies) {
	std::vector<int>a = std::vector<int>();
	int* array = new int[11] {1, 2, 3, 5, 4, 1, 2, 7, 9, 9, 3};
	for (int i = 0; i < 11; i++)
		a.push_back(array[i]);
	std::vector<int> b = no_replys(a);
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
}


TEST(treetests, yyyy) {
	ofstream fout;
	fout.open("C:\\Proganiy\\Aisd 4\\Aisd-laba1\\tree_out.txt");
	fout << "hello";
}