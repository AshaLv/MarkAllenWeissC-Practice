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
// #include "list/CircularQueue.cpp"
using namespace std;

int main() {
	try
	{
		SingleLinkedList<int> s;
		s.push_front(1);
		s.push_front(2);
		s.push_front(3);
		s.push_front(4);
		s.push_front(5);
		s.push_front(6);
		s.push_front(7);
		s.push_front(8);
		s.make_circle();
		cout << s.contain_circle() << "\n";
	}	
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



