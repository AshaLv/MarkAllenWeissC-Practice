#include <iostream>
// #include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
// #include "application/StackApplication.cpp"
// #include <string>
#include "list/TwoStacks.cpp"

using namespace std;

int main() {
	try
	{
		TwoStacks<int> s;
		for (short i = 0; i < 16; i++)
		{
			s.push2(i);
		}
		cout << s.top2() << "\n";
		s.pop1();
		cout << s.top1() << "\n";
		
	}
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



