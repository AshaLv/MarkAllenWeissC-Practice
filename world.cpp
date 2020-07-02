#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
#include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
int main() {
	//prepare data
	Vector<int> v;
	v.push_back(1);
	//solve problem
	cout << v[0] << "\n";
	cout << v[-1] << "\n";
	cout << v[1] << "\n";
}



