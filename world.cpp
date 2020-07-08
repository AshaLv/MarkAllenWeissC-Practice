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
	string pascal_code = "#Pascalbegin324232(dsj3)[dsjfs]{beginfsgfhsfgsend}end";
	string c_code = "#C++/*hjfklhj*/begin324232(dsj3)[dsjfs]{fsgfhsfgs}end";
	// solve problem
	try
	{
		cout << "checking pascal code:\n";
		StackApplication::check_balancing_symbols_for_all_languages(pascal_code);
		cout << "checking c++ code:\n";
		StackApplication::check_balancing_symbols_for_all_languages(c_code);
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	
	
	
	
}



