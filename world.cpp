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
	//prepare data
	string postfix_expression[] = {"3","4","+","3","5","+","+","\n"};
	// solve problem
	try
	{
		cout << "postfix expression evaluation: ";
		cout << StackApplication::evaluate_postfix_expression(postfix_expression) << "\n";
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	
}



