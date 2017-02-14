// Assignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack_manipulation.h"
#include <iostream>

using namespace std;

struct item { // individual item on stack
	std::string id;
	struct item *p_id; // next item on list
};

struct stack { // the entire stack
	struct item* top; // top item of stack
	void push(std::string x);
	std::string pop();
	std::string peek(); // look at top item of stack
	void copy();
	bool empty();
};

void stack::push(std::string x) {
	item *next = new item();
	next->p_id = top;
	next->id = x;
	top = next;
}

std::string stack::pop() {
	std::string save = top->id;
	struct item* prev_top = top;
	top = top->p_id;
	delete prev_top;
	return save;
}

std::string stack::peek() {
	return top->id;
}

void stack::copy() {
	item *copy = new item();
	copy->p_id = top;
	copy->id = top->id;
	top = copy;
}

bool stack::empty() {
	// needs to be checked
	if (top->id == "") return true;
	else return false;
}

int main()
{
	stack stack;
	stack.push("50");
	stack.push("25");
	stack.pop();
	std::cout << "Test";
    return 0;
}

