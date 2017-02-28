#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "stack_manipulation.h"

using namespace std;

int main()
{
	std::vector<string> inputFileParameter;
	
	//readInputFile(inputFileParameter);
	
	// Wait for user to press 'Enter' to exit program
	system("pause");
	
	return 0;
}

void readInputFile(vector<string>& inputFileParameter)
{
	string singleLine = "";
	ifstream inputFile("input.txt");

	cout << "\nThe following is what the input file contains: \n\n";

	if (inputFile.is_open())
	{
		while (!inputFile.eof() && getline(inputFile, singleLine))
		{
			std::cout << singleLine << std::endl;

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
}