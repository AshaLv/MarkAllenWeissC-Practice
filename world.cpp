#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
#include "list/Vector.cpp"
#include "application/VectorApplication.cpp"
int main() {
	//prepare data
	Vector<int> d1;
	int i2[] = {5,6,-1};
	VectorApplication<int>::populate(d1, i2);
	Vector<int>::iterator itr = d1.begin();
	// solve problem
	d1.insert(itr,7);
	d1.erase(itr);
	VectorApplication<int>::printAll(d1);
}



