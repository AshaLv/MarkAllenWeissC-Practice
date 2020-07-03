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
	Vector<int>::iterator begin_itr = v.begin();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4444);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	++begin_itr;
	v.erase(begin_itr);//second element
	v.insert(begin_itr,2);
	//solve problem
	VectorApplication<int>::printAll(v);
}



