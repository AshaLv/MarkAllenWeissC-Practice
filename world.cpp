#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
#include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
int main() {
	//prepare data
	DoubleLinkedList<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	DoubleLinkedList<int>::const_iterator itr = d1.begin();
	d1.insert(itr+3,4);
	d1.insert(itr,444);
	itr = d1.begin();
	DoubleLinkedList<int>::const_iterator end_itr = d1.end();
	//solve problem
	while(itr != end_itr) cout << *(itr++) << "\n";
}



