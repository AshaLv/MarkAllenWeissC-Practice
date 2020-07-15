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
// #include "list/CircularQueue2.cpp"

using namespace std;

int main() {
	try
	{	
		SingleLinkedList<int> s;
		s.push_front(1);
		s.push_front(2);
		s.push_front(3);
		s.push_front(4);
		s.add_before(++s.begin(),222);
		s.erase(++s.begin());
		SingleLinkedList<int>::const_iterator begin_itr = s.begin();
		SingleLinkedList<int>::const_iterator end_itr = s.end();
		while(begin_itr!=end_itr) cout << *begin_itr++ << "\n";
	}	
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



