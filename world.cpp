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
	s1.push_back(1);
	s1.push_back(2);
	s1.push_front(44444);
	SingleLinkedList<int>::const_iterator c = s1.begin();
	SingleLinkedList<int>::const_iterator end_itr = s1.end();
	//solve problem
	cout << s1.size() << "\n";
	while (c != end_itr) cout << *(c++) << "\n";
	s1.contain(4);
	s1.remove(44);
	s1.remove(44444);
	c = s1.begin();
	end_itr = s1.end();
	while (c != end_itr) cout << *(c++) << "\n";
}



