#include "stdafx.h"
#include "stack_manipulation.h"
#include "SymbolTable.h"
#include <iostream>
#include <map>

using namespace std;

stack_manipulation::stack::stack():symbolTableMap() {
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

void stack_manipulation::stack::pushVariable(std::string x, std::map<std::string, int> *map) {
	item *next = new item();
	next->p_id = top;
	next->id = x;
	next->map = map;
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

std::pair<std::string, std::map<std::string, int> *> stack_manipulation::stack::popVariable()
{
	std::string save = top->id;
	std::map<std::string, int> *saveMap = top->map;
	struct item* prev_top = top;
	top = top->p_id;
	delete prev_top;
	return std::pair<std::string, std::map<std::string, int> *> {save, saveMap};
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
	std::map <std::string, int> ::iterator it;
	it = symbolTableMap.find("a");
	if (it == symbolTableMap.end())
	{
		symbolTableMap.insert(std::pair<std::string, int>("a", 0));
	}
	push(symbolTableMap["a"]);

}

void stack_manipulation::stack::lvalue(std::string l) {
	// pushes address of data location l onto stack
	// Get line from the input file
	std::map <std::string, int> ::iterator it;
	it = symbolTableMap.find("a");
	if (it == symbolTableMap.end())
	{
		symbolTableMap.insert(std::pair<std::string, int>("a", 0));
	}
	pushVariable("a", &symbolTableMap);
	//std::string *address = &l;
	//item *next = new item();
	//next->p_id = top;
	//next->id = *address;
	//top = next;
}

void stack_manipulation::stack::colonEq() {
	// stack top is placed by the lvalue below it and both are popped
	std::string value = pop();
	std::pair<std::string, std::map<std::string, int> *> variable = popVariable();
	variable.second[variable.first] = value;	// value from the first pop		// map second to the pair
}

void stack_manipulation::stack::op(std::string op) {
	// op gets operator from file
}
