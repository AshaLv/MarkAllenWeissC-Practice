#include <iostream>
using namespace std;
#include "datastructure/SingleLinkedList.cpp"
#include "application/LinkedListApplication.cpp"





int main() {
	//prepare data
	SingleLinkedList<int> single_linked_list;
	single_linked_list.push_back(111);
	single_linked_list.push_back(2);
	single_linked_list.push_back(3);
	single_linked_list.push_back(4);
	SingleLinkedList<int>::iterator begin = single_linked_list.begin();
	SingleLinkedList<int>::iterator end = single_linked_list.end();
	//solve problem
	++begin;
	single_linked_list.adjacentElementsSwap(++begin);
	begin = single_linked_list.begin();
	while (begin != end) {
		cout << *(begin++) << "\n";
	}
	
}



