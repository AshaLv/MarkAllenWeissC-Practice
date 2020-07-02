#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
#include "list/Vector.cpp"
#include "application/VectorApplication.cpp"
int main() {
	//prepare data
	Vector<int> v;
	v.push_back(1);
	v.insert(0,3);
	v.insert(2,4);
	v.insert(0,433);
	v.pop_back();
	v.erase(1);
	//solve problem
	VectorApplication<int>::printAll(v);
}



