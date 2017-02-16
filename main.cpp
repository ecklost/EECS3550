#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
// Retrieves the file line by line and stores each line into a vector of strings.

	string singleLine = "";				// Get line of text from the input file
	ifstream read("input.txt");

	if (read.is_open())
	{
		while (!read.eof() && getline(inputFile, singleLine))
		{
			if (singleLine.compare("</end>") == 0)
				break;					// End of file
			else
			{
				inputHolder.push_back(line);
				singleLine = "";
			}
		}
		read.close();
	}
	else cout << "Cannot open file: Check file structure.";

	// Wait for user to press 'Enter' to exit program
	char WaitChar;
	cout << "\nProccessing finished. Press 'Enter' to exit the program: \n\n";
	cin.get(WaitChar);
	return 0;
}