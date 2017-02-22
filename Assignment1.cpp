// Assignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack_manipulation.h"
#include "arithmetic.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	stack_manipulation::stack stack;
	/*stack.push("5"); // this line and next gathered from file
	stack.push("4");
	stack.pop();
	stack.pop();
	std::cout << stack.empty();
	std::cout << "Test";*/

	stack.lvalue("n");
	stack.push("5");
	stack.colonEq();

	stack.lvalue("f");
	stack.push("1");
	stack.colonEq();

	stack.lvalue("t");
	stack.rvalue("f");
	stack.colonEq();

	stack.lvalue("i");
	stack.rvalue("n");
	stack.colonEq();

	// Wait for user to press 'Enter' to exit program
	char WaitChar;
	cout << "\nProccessing finished. Press 'Enter' to exit the program: \n\n";
	cin.get(WaitChar);
	return 0;
}

