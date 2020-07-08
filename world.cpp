#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
#include "list/DoubleLinkedList.cpp"
#include "application/LinkedListApplication.cpp"
#include "list/Vector.cpp"
#include "application/VectorApplication.cpp"
int main() {
	//prepare data
	DoubleLinkedList<int> d1;
	int i2[] = {5,6,7,8,9,-1};
	LinkedListApplication<int>::populate(d1, i2);
	DoubleLinkedList<int>::iterator itr;
	//solve problem
	d1.insert(itr,3);
	
}



