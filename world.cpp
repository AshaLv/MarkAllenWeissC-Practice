#include <iostream>
using namespace std;
#include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
int main() {
	//prepare data
	SingleLinkedList<int> s1;
	s1.push_back(3);
	s1.push_back(2);
	s1.push_back(1);
	s1.push_back(421);
	s1.push_back(13214);
	s1.push_back(10);
	s1.push_back(8);
	s1.push_back(9);
	SingleLinkedList<int>::const_iterator c = s1.begin();
	SingleLinkedList<int>::const_iterator end_itr = s1.end();
	//solve problem
	while (c != end_itr) cout << *(c++) << "\n";
}



