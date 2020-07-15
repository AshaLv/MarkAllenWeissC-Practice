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
#include "list/Stack2.cpp"

using namespace std;

int main() {
	try
	{
		Stack2<int> s;
		s.push(1);
		s.push(2);
		Stack2<int> s2 = s;
		s2.pop();
		cout << s2.top() << "\n";
	}
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



