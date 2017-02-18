#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	vector<string> inputFileParameter;							// Vector that contains the input strings
	
	readInputFile(inputFileParameter);							// Calls the method that reads from the input file
	
	// Wait for user to press 'Enter' to exit program
	system("pause");
	
	return 0;
}

void readInputFile(vector<string>& inputFileParameter)
{
	string singleLine = "";								// Stores each line in the input file as a string
	ifstream inputFile("input.txt");

	cout << "\nThe following is what the input file contains: \n\n";

	if (inputFile.is_open())
	{
		while (!inputFile.eof() && getline(inputFile, singleLine))	// While not at the end of the file, read file line by line
		{
			std::cout << singleLine << std::endl;		// Outputs every single line from the input File

			if (singleLine.compare("halt") == 0)		// Checks if the file contains the following string: halt, if encountered, end the file
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