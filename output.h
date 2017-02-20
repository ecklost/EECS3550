#pragma once
#include <iostream>
#include <fstream>
#include "stack_manipulation.h"

class output
{
public:
	output();
	void show(std::ofstream outfile, std::string msg);
	void print(std::ofstream outfile, stack_manipulation::stack stack);
	~output();
};

