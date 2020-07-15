#include <iostream>
// #include "list/SingleLinkedList.cpp"
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
// #include "list/CircularQueue.cpp"
#include "list/CircularQueue2.cpp"

using namespace std;

int main() {
	try
	{	
		CircularQueue2<int> q;
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.enqueue(4);
		CircularQueue2<int> q2 = q;
		q.dequeue();
		q.dequeue();
		cout << q.dequeue() << "\n";
		cout << q2.dequeue() << "\n";
	}	
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



