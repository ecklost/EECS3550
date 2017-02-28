#include "stdafx.h"
#include "stack_manipulation.h"
#include "SymbolTable.h"
#include "operators.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

stack_manipulation::stack::stack() {
	map_vec.push_back(new std::map <std::string, int>);
	rvalueTable = map_vec[0];
	lvalueTable = map_vec[0];
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
	it = (*rvalueTable).find(l);
	if (it == (*rvalueTable).end())
	{
		(*rvalueTable).insert(std::pair<std::string, int>(l, 0));
	}
	

	push(std::to_string((*rvalueTable)[l]));

}

void stack_manipulation::stack::lvalue(std::string l) {
	// pushes address of data location l onto stack
	// Get line from the input file
	std::map <std::string, int> ::iterator it;
	it = (*lvalueTable).find(l);
	if (it == (*lvalueTable).end())
	{
		(*lvalueTable).insert(std::pair<std::string, int>(l, 0));
	}
	pushVariable(l, &(*lvalueTable));
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
	(*variable.second)[variable.first] = stoi(value);	// value from the first pop		// map second to the pair
}

void stack_manipulation::stack::op(std::string op) {
	// op gets operator from file
	// Since compare returns a 0 if the statement is true, we need to add
	// in the '!'
	// arithmetic
	if (!op.compare("+")) {
		// +
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x + y));
	}
	else if (!op.compare("-")) {
		// -
		int y = stoi(pop());
		int x = stoi(pop());
		x = x - y;
		stack::push(std::to_string(x));
	}
	else if (!op.compare("*")) {
		// *
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x * y));
	}
	else if (!op.compare("/")) {
		// /
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x / y));
	}
	else if (!op.compare("div")) {
		// mod
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x % y));
	}

	// logical
	else if (!op.compare("&")) {
		// &
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x && y));
	}
	else if (!op.compare("|")) {
		// |
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x || y));
	}
	else if (!op.compare("!")) {
		// !
		int x = stoi(pop());
		stack::push(std::to_string(!x));
	}

	// relational
	else if (!op.compare("<>")) {
		// <> or not equals
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x != y));
	}
	else if (!op.compare("<=")) {
		// <=
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x <= y));
	}
	else if (!op.compare(">=")) {
		// >=
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x >= y));
	}
	else if (!op.compare("<")) {
		// <
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x < y));
	}
	else if (!op.compare(">")) {
		// >
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x > y));
	}
	else if (!op.compare("==")) {
		// ==
		int y = stoi(pop());
		int x = stoi(pop());
		stack::push(std::to_string(x == y));
	}
	else {
		std::cout << "Invalid operator";
		exit(1);
	}
}

void stack_manipulation::stack::assignLabels(std::fstream& inputFile) {
	inputFile.seekg(std::ios::beg);
	std::string singleLine = "";
	int lineNumber = 1;
	while (!inputFile.eof() && getline(inputFile, singleLine))
	{
		//std::cout << singleLine << std::endl;
		if (!singleLine.find("label") || !singleLine.find(" label") || !singleLine.find("  label")) {
			while (!singleLine.find(" label") || !singleLine.find("  label")) {
				singleLine = singleLine.erase(0,1); // remove leading spaces
			}
			if (singleLine[singleLine.size() - 1] == '\r') { singleLine = singleLine.substr(0, singleLine.size() - 1); }
			std::size_t postwo = singleLine.find_last_not_of(" \t");
			if (std::string::npos != postwo) { singleLine = singleLine.substr(0, postwo + 1); } // for demo.jaz
			labelTable.insert(std::pair<std::string, int>(singleLine, lineNumber));
		}
		singleLine = ""; // Empty line so it's ready for the next one
		lineNumber++;
	}
	inputFile.clear();
	inputFile.seekg(std::ios::beg); // Start back at beginning
}

int stack_manipulation::stack::getLabel(std::string labelName)
{
	// Search labelTable until label is found, then return entry.
	return labelTable.find("label " + labelName)->second;
}

std::fstream& stack_manipulation::stack::goTo(std::fstream& inputFile, int lineNumber)
{
	inputFile.seekg(std::ios::beg);
	for (int index = 0; index < (lineNumber - 1); ++index)
	{
		inputFile.ignore(256, '\n');
	}
	return inputFile;
}

std::fstream& stack_manipulation::stack::goFalse(std::fstream& inputFile, std::string labelName)
{
	if (stack::empty())
	{
		cout << "Stack is empty, therefore there is nothing to check" << endl;
		exit(1);
	}
	
	std::string check = stack::pop();

	if (!check.compare("0"))
	{
		// get line number actually
		goTo(inputFile, getLabel(labelName));
	}

	return inputFile;
}

std::fstream& stack_manipulation::stack::goTrue(std::fstream& inputFile, std::string labelName)
{
	if (stack::empty())
	{
		cout << "Stack is empty, therefore there is nothing to check" << endl;
		exit(1);
	}

	std::string check = stack::pop();

	if (!check.compare("1"))
	{	
		goTo(inputFile, getLabel(labelName));
	}
	return inputFile;
}

void stack_manipulation::stack::halt()
{
	// Handled in main.
}

void stack_manipulation::stack::begin()
{
	lvalueTable = new std::map <std::string, int>;
	map_vec.push_back(lvalueTable);
}

void stack_manipulation::stack::end()
{
	delete rvalueTable;
	rvalueTable = lvalueTable;
	map_vec.pop_back();
}

void stack_manipulation::stack::ret()
{
	lvalueTable = map_vec[map_vec.size() - 2];
}

void stack_manipulation::stack::call()
{
	rvalueTable = lvalueTable;
}