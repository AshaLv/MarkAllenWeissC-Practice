#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
#include "list/DoubleLinkedList.cpp"
#include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
int main() {
	//prepare data
	DoubleLinkedList<int> d1;
	DoubleLinkedList<int> d2;
	int i1[] = {1,2,3,4,-1};
	int i2[] = {5,6,7,8,9,-1};
	LinkedListApplication<int>::populate(d1, i1);
	LinkedListApplication<int>::populate(d2, i2);
	DoubleLinkedList<int>::iterator itr = d1.begin();
	// //solve problem
	d1.splice(itr,d2);
	LinkedListApplication<int>::printAll(d1);
	LinkedListApplication<int>::printAll(d2);
}



