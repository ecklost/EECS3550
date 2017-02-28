#pragma once
#include <iostream>
#include <fstream>
#include "stack_manipulation.h"

class output
{
public:
	output();
	void show(std::fstream outfile, std::string msg);
	void print(std::fstream outfile, stack_manipulation::stack stack);
	~output();
};

