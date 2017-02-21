#pragma once
#include <iostream>
#include <map>
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
		std::map <std::string, int> symbolTableMap;
		struct item* top;
		void push(std::string x);
		void pushVariable(std::string x, std::map<std::string, int> *map);
		std::pair<std::string, std::map<std::string, int> *> popVariable()
		std::string pop();
		std::string peek();
		void copy();
		bool empty();
		void rvalue(std::string l);
		void lvalue(std::string l);
		void colonEq();
		void op(std::string op);
	};
};

