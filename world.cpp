#include <iostream>
#include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
// #include "application/StackApplication.cpp"
// #include <string>
// #include "list/TwoStacks.cpp"
// #include "list/ThreeStacks.cpp"
// #include "list/Deque.cpp"
// #include "list/SelfAdjustingVector.cpp"
// #include "list/SelfAdjustingLinkedList.cpp"
// #include "list/Stack2.cpp"
// #include "list/Queue2.cpp"
#include "list/CircularQueue.cpp"

using namespace std;

int main() {
	try
	{
		CircularQueue<int> q;
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.enqueue(4);
		cout << q.dequeue() << "\n";
		cout << q.dequeue() << "\n";
		q.enqueue(111);
		q.enqueue(222);
		cout << q.dequeue() << "\n";
		cout << q.dequeue() << "\n";
		cout << q.dequeue() << "\n";
		cout << q.dequeue() << "\n";
	}	
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



