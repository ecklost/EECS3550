#pragma once
#include <iostream>
#include <map>
#include <vector>
namespace stack_manipulation
{
	struct item {
		std::string id;
		struct item *p_id;
		std::map<std::string, int> *map;
	};
	struct stack {
		stack();
		~stack();
		std::vector <std::map <std::string, int> *> map_vec; // Holds values
		std::map <std::string, int> *rvalueTable;
		std::map <std::string, int> *lvalueTable;
		std::map <std::string, int> labelTable; // Assigns labels
		char labelChar;
		struct item* top; // For the function, see peek();

		void push(std::string x); // Standard stack push.
		void pushVariable(std::string x, std::map<std::string, int> *map); // For rvalue and lvalue, push variables.
		std::pair<std::string, std::map<std::string, int> *> popVariable(); // For rvalue and lvalue, pop variables.
		std::string pop(); // Standard stack pop.
		std::string peek(); // See top item of stack.
		void copy(); // Copy top of stack.
		bool empty(); // Checks to see if stack is empty.
		void rvalue(std::string l); // Pushes contents of data location l onto stack
		void lvalue(std::string l); // Pushes address of data location l onto stack
		void colonEq(); // Stack top is placed by the lvalue below it and both are popped
		void op(std::string op); // Do operations
		void assignLabels(std::fstream& inputFile); // Assigns labels to a table for reference
		int getLabel(std::string labelName); // Get the line number where the label is.
		std::fstream& goTo(std::fstream& inputFile, int lineNumber); // Go to a specific line in code
		std::fstream& goFalse(std::fstream& inputFile, std::string labelName); // Go to a specific line if top is 0.
		std::fstream& goTrue(std::fstream& inputFile, std::string labelName);  // Go to a specific line if top is 1.
		void halt(); // Handled in main.
		void stack_manipulation::stack::begin(); // Begin function call.
		void stack_manipulation::stack::end(); // End function call.
		void stack_manipulation::stack::ret(); // Return to previous function.
		void stack_manipulation::stack::call(); // Go to function.
	};
};

