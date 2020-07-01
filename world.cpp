#include <iostream>
using namespace std;
#include "list/SingleLinkedList.cpp"
#include "list/DoubleLinkedList.cpp"
#include "application/IterationApplication.cpp"

int main() {
	//prepare data
	DoubleLinkedList<int> double_linked_list;
	double_linked_list.push_back(111);
	double_linked_list.push_back(2);
	double_linked_list.push_back(3);
	double_linked_list.push_back(4);
	DoubleLinkedList<int>::iterator begin = double_linked_list.begin();
	DoubleLinkedList<int>::iterator end = double_linked_list.end();
	//solve problem
	cout << *(IterationApplication<DoubleLinkedList<int>::iterator, int>::find(begin, end, 344)) << "\n";
	
}



