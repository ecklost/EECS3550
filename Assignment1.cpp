// Assignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack_manipulation.h"
#include "output.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	stack_manipulation::stack stack;
	std::vector<string> inputFileParameter;
	output output;
	
	string singleLine = "";
	fstream inputFile("operatorsTest.jaz");
	fstream outputFile("output.out");
	outputFile.open("output.out");
	stack.assignLabels(inputFile);

	cout << "\nThe following is what the input file contains: \n\n";
	//stack.push("0");
	//stack.goFalse(inputFile, "out");

	if (inputFile.is_open())
	{
		while (!inputFile.eof() && getline(inputFile, singleLine))
		{
			// Trim leading spaces
			std::size_t pos = singleLine.find_first_not_of(" \t");
			if (std::string::npos != pos) { singleLine = singleLine.substr(pos); } // remove leading spaces
			//std::cout << singleLine << std::endl;
			if (singleLine.find("show") == 0) {
				std::cout << singleLine.erase(0, 4) << "\n";
				outputFile << singleLine.erase(0, 4) << "\n";
			}

			if (singleLine.compare("halt") == 0)
				break;
			else
			{
				inputFileParameter.push_back(singleLine);
				singleLine = "";						// Empty line so it's ready for the next one
			}
		}
		inputFile.close();
	}
	else
		cout << "Error: File is unable to open.  Check the location and the name of the file for possible errors.";
	
/*std::size_t position = singleLine.size();
			// Trim spaces from the end
			while (singleLine[position] == ' ' && position > 0) --pos;

			if (position == 0) { // string consists entirely of spaces }
			
			std::string labelName = singleLine.substr(singleLine.find_last_of(' ', position));
*/

	// Wait for user to press 'Enter' to exit program
	char WaitChar;
	cout << "\nProccessing finished. Press 'Enter' to exit the program: \n\n";
	cin.get(WaitChar);
	return 0;
}

