#include "string.h"
#include <iostream>

int main()
{
	// Length
	std::cout << string::Length("catdog") << std::endl << std::endl;

	// Copy and ConCat
	char * a = "dog";
	char * b = "cat";

	string::Copy(a, b);
	string::ConCat(a, "\n");
	string::WriteToConsole(a);

	// ConCat

	// Compare

	// Resize

	// WriteToConsole
	
	// Base constructor
	string::WriteToConsole("Base Constructor: ");
	string test;
	test.WriteToConsole();
	string::WriteToConsole("\n\n");

	// overloaded constructor
	string::WriteToConsole("Overloaded Constructor: ");
	string cat("cat");
	cat.WriteToConsole();
	string::WriteToConsole("\n\n");

	// = operator
	string::WriteToConsole("operator=: ");
	string cat2;
	cat2 = cat;
	cat2.WriteToConsole();
	string::WriteToConsole("\n\n");
	
	system("pause");
	return 0;
}