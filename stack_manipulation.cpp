#include "stdafx.h"
#include "stack_manipulation.h"
#include <iostream>

using namespace std;

stack_manipulation::stack::stack() {
	top = NULL;
}

stack_manipulation::stack::~stack() {
}

void stack_manipulation::stack::push(std::string x) {
	item *next = new item();
	next->p_id = top;
	next->id = x;
	top = next;
}

std::string stack_manipulation::stack::pop()
{
	std::string save = top->id;
	struct item* prev_top = top;
	top = top->p_id;
	delete prev_top;
	return save;
}

std::string stack_manipulation::stack::peek()
{
	return top->id;
}

void stack_manipulation::stack::copy() {
	item *copy = new item();
	copy->p_id = top;
	copy->id = top->id;
	top = copy;
}

bool stack_manipulation::stack::empty()
{
	// needs to be checked
	if (top == NULL) return true;
	else return false;
}

void stack_manipulation::stack::rvalue(std::string l) {
	// pushes contents of data location l onto stack
}

void stack_manipulation::stack::lvalue(std::string l) {
	// pushes address of data location l onto stack
	std::string *address = &l;
	item *next = new item();
	next->p_id = top;
	next->id = *address;
	top = next;
}

void stack_manipulation::stack::colonEq() {
	// stack top is placed by the lvalue below it and both are popped
}

void stack_manipulation::stack::op(std::string op) {
	// op gets operator from file
}
