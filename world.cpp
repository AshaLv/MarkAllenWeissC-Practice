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
#include "list/Deque.cpp"

using namespace std;

int main() {
	try
	{
		Deque<int> d;
		d.push(1);
		d.push(2);
		d.push(3);
		cout << d.pop() << "\n";
		cout << d.eject() << "\n";
	}
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



