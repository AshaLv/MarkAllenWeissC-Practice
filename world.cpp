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
#include "list/Queue2.cpp"

using namespace std;

int main() {
	try
	{
		Queue2<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		Queue2<int> q2 = q;
		q2.pop();
		cout << q.front() << "\n";
		cout << q2.front() << "\n";
	}
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



