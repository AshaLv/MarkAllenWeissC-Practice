#include <iostream>
using namespace std;
#include "datastructure/SingleLinkedList.cpp"
#include "datastructure/DoubleLinkedList.cpp"

int main() {
	//prepare data
	DoubleLinkedList<int> double_linked_list;
	double_linked_list.push_back(111);
	double_linked_list.push_back(2);
	double_linked_list.push_back(3);
	double_linked_list.push_back(4);
	DoubleLinkedList<int>::iterator begin = double_linked_list.begin();
	DoubleLinkedList<int>::iterator end = double_linked_list.end();
	double_linked_list.adjacentElementsSwap(++begin);
	//solve problem
	begin = double_linked_list.begin();
	while (begin != end) {
		cout << *(begin++) << "\n";
	}
	
}



