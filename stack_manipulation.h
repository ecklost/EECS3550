#pragma once
#include <iostream>
namespace stack_manipulation
{
	struct item {
		std::string id;
		struct item *p_id;
	};
	struct stack {
		stack();
		~stack();
		struct item* top;
		void push(std::string x);
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

