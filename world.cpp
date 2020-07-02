#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
#include "list/DoubleLinkedList.cpp"
#include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
int main() {
	//prepare data
	DoubleLinkedList<int> l1;
	int p1[] = {1,2,3,4,5,-1};
	LinkedListApplication<int>::populate(l1,p1);
	//solve problem
	int r = l1.josephus_game(2);
	cout << r << "\n";
	// for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";	
}



