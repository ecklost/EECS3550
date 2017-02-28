#include "stdafx.h"
#include "output.h"
#include "stack_manipulation.h"
#include <iostream>
#include <fstream>
#include <string>


output::output() {

}

void output::show(std::fstream outfile, std::string msg) {
	outfile.open("output.out");
	std::cout << msg << "\n"; //message will be stuff after "show" from .jaz file
	outfile.close();
}

void output::print(std::fstream outfile, stack_manipulation::stack stack) {
	// output to file
	outfile.open("output.out");
	std::cout << stack.top->id << "\n";
	outfile.close();
}


output::~output() {

}
