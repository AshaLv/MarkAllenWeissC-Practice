#include <iostream>
using namespace std;
// #include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/IterationApplication.cpp"
#include "list/Vector.cpp"
#include "application/VectorApplication.cpp"
int main() {
	//prepare data
	Vector<int> v1;
	Vector<int> v2;
	int p1[] = {1,2,3,4,5,6,-1};
	int p2[] = {3,44,666,-1};
	VectorApplication<int>::populate(v1,p1);
	VectorApplication<int>::populate(v2,p2);
	//solve problem
	Vector<int> v = VectorApplication<int>::common(v1,v2);
	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";	
}



