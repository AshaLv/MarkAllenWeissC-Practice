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
#include "list/SelfAdjustingVector.cpp"
#include "list/SelfAdjustingLinkedList.cpp"

using namespace std;

int main() {
	try
	{
		SelfAdjustingVector<int> s;
		s.push(1);
		s.push(2);
		s.find(1);
		cout << s.front() << "\n";
		SelfAdjustingLinkedList<int> s2;
		s2.push(444);
		s2.push(555);
		s2.find(444);
		cout << s2.front() << "\n";
	}
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



