#include <iostream>
#include "./datastructure/Vector.cpp"
#include "./datastructure/LinkedList.cpp"
#include "./datastructure/Stack.cpp"
#include "./datastructure/Queue.cpp"
#include "./application/StackApplication.cpp"


using namespace std;
using namespace std::chrono;

int main() {
	//prepare data
	Vector<int> v; //Vector is a good list kind, but not good at insert and delete operations
	LinkedList<int> ll; //LinkedList is a good list kind, and good at insert and delete operations in the 0th position;
	Stack<int> s; //Stack is a special list, but very useful
	Queue<int> q; //Queue is a special list, but very useful
	//solve problem
	char source[] = {'3','+','2','*','5','+','(','1','+','1',')','*','3'};
	float result = StackApplication::basicCalculate(source,13);
	cout << result << "\n";
	cout << 3+2*5+(1+1)*3 << "\n";
}



