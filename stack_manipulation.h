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
		std::vector <std::map <std::string, int> *> map_vec;
		std::map <std::string, int> *rvalueTable;
		std::map <std::string, int> *lvalueTable;
		std::map <std::string, int> labelTable;

		struct item* top; // for the function, see peek();
		void push(std::string x);
		void pushVariable(std::string x, std::map<std::string, int> *map);
		std::pair<std::string, std::map<std::string, int> *> popVariable();
		std::string pop();
		std::string peek();
		void copy();
		bool empty();
		void rvalue(std::string l);
		void lvalue(std::string l);
		void colonEq();
		void op(std::string op);
		char labelChar;
		void assignLabels(std::fstream& inputFile);
		int getLabel(std::string labelName);
		std::fstream& goTo(std::fstream& inputFile, int lineNumber);
		std::fstream& goFalse(std::fstream& inputFile, std::string labelName);
		std::fstream& goTrue(std::fstream& inputFile, std::string labelName);
		void halt();
		void stack_manipulation::stack::begin();
		void stack_manipulation::stack::end();
		void stack_manipulation::stack::ret();
		void stack_manipulation::stack::call();
	};
};

