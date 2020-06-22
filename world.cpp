#include <iostream>

using namespace std;
using namespace std::chrono;

#include "./datastructure/Vector.cpp"
#include "./datastructure/LinkedList.cpp"
#include "./datastructure/Stack.cpp"
#include "./datastructure/Queue.cpp"
#include "./application/StackApplication.cpp"
#include "./Application/VectorApplication.cpp"

int main() {
	//prepare data
	Vector<int> v; //Vector is a good list kind, but not good at insert and delete operations
	LinkedList<int> ll; //LinkedList is a good list kind, and good at insert and delete operations in the 0th position;
	Stack<int> s; //Stack is a special list, but very useful
	Queue<int> q; //Queue is a special list, but very useful

	Vector<int> L;
	Vector<int> P;
	int p[] = {1,2,3,4,5,6,7,8,9,-1};
	int another_p[] = {0,2,4,6,-1};
	VectorApplication<int>::populate(L,p);
	VectorApplication<int>::populate(P,another_p);
	//solve problem
	VectorApplication<int>::printLots(L,P);
}



