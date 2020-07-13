#include <iostream>
// #include "list/SingleLinkedList.cpp"
// #include "list/DoubleLinkedList.cpp"
// #include "application/LinkedListApplication.cpp"
// #include "list/Vector.cpp"
// #include "application/VectorApplication.cpp"
#include "application/StackApplication.cpp"
#include <string>
using namespace std;

int main() {
	try
	{
		string postfix_expression[] = {"3","4","+","3","5","+","+","4","*","\n"};
		// string postfix_expression[] = {"3","4","+","\n"};
		string infix_expression = StackApplication::postfix_to_infix(postfix_expression);
		cout << infix_expression << "\n";
		cout << "\n";
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	
}



