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
		s.print();
		s.rprint();
	}
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



