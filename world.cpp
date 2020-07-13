#include <iostream>
// #include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
// #include "application/StackApplication.cpp"
// #include <string>
// #include "list/TwoStacks.cpp"
#include "list/ThreeStacks.cpp"

using namespace std;

int main() {
	try
	{
		ThreeStacks<int> s;
		s.push1(1);
		s.push2(2);
		s.push3(3);
		s.pop1();
		s.pop2();
		s.push2(324);
		s.push1(111);
		ThreeStacks<int> s2 = s;
		cout << s2.top1() << " " << s.top2() << " " << s.top3() << " \n";
	}
	catch(const char * msg)
	{
		cerr << msg << '\n';
	}
}



