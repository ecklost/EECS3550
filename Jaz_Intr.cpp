// This is the main file for the program. Naturally, the code starts here.
// It will only reference stack_manipulation for the stack. All other code
// files (not included in the final product) are snippets meant for design
// purposes. 

#include "stdafx.h"
#include "stack_manipulation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	// Instantiate stack.
	stack_manipulation::stack stack;
	std::vector<std::streamoff> callStack;
	
	// Additional set-up.
	string singleLine = "";
	fstream inputFile("foo.jaz", ios_base::in | ios_base::binary); // Insert file that you wish to use here.
	ofstream outputFile("outputFile.out"); // Output file.
	stack.assignLabels(inputFile); // Assign labels to a line number.

	cout << "\nThe following is what the input file contains: \n\n";

	if (inputFile.is_open())
	{
		while (!inputFile.eof() && getline(inputFile, singleLine))
		{
			// Trim leading spaces
			std::size_t pos = singleLine.find_first_not_of(" \t");
			if (std::string::npos != pos) { singleLine = singleLine.substr(pos); } // remove leading spaces
			if (singleLine[singleLine.size() - 1] == '\r') { singleLine = singleLine.substr(0, singleLine.size() - 1); }
			std::size_t postwo = singleLine.find_last_not_of(" \t");
			if (std::string::npos != postwo) { singleLine = singleLine.substr(0, postwo + 1); } // for foo.jaz
			
			// Interpret line
			// Output
			if (singleLine.find("show") == 0) {
				std::cout << singleLine << "\n";
				outputFile << singleLine.erase(0, 5) << "\n";
			}
			else if (singleLine.find("print") == 0) {
				std::cout << stack.top->id << "\n";
				outputFile << stack.top->id << "\n";
			}
			// Stack Manipulation
			else if (singleLine.find("push") == 0) {
				stack.push(singleLine.erase(0, 5));
			}
			else if (singleLine.find("rvalue") == 0) {
				stack.rvalue(singleLine.erase(0, 7));
			}
			else if (singleLine.find("lvalue") == 0) {
				stack.lvalue(singleLine.erase(0, 7));
			}
			else if (singleLine.find("pop") == 0) {
				stack.pop();
			}
			else if (singleLine.find(":=") == 0) {
				stack.colonEq();
			}
			else if (singleLine.find("copy") == 0) {
				stack.copy();
			}
			// Control Flow
			else if (singleLine.find("goto") == 0) {
				stack.goTo(inputFile, stack.getLabel(singleLine.erase(0, 5)));
			}
			else if (singleLine.find("gofalse") == 0) {
				stack.goFalse(inputFile, singleLine.erase(0, 8));
			}
			else if (singleLine.find("gotrue") == 0) {
				stack.goTrue(inputFile, singleLine.erase(0, 7));
			}
			// Subprogram Control
			else if (singleLine.find("begin") == 0) {
				stack.begin();
			}
			else if (singleLine.find("end") == 0) {
				stack.end();
			}
			else if (singleLine.find("return") == 0) {
				stack.ret();
				inputFile.seekg(callStack[callStack.size()-1], std::ios_base::beg);
				callStack.pop_back();
			}
			else if (singleLine.find("call") == 0) {
				stack.call();
				callStack.push_back(inputFile.tellg());
				stack.goTo(inputFile, stack.getLabel(singleLine.erase(0, 5)));
			}
			// Operators
			else if (!singleLine.compare("+"))
			{
				stack.op("+");
			}
			else if (!singleLine.compare("-"))
			{
				stack.op("-");
			}
			else if (!singleLine.compare("*"))
			{
				stack.op("*");
			}
			else if (!singleLine.compare("/"))
			{
				stack.op("/");
			}
			else if (!singleLine.compare("div"))
			{
				stack.op("div");
			}
			else if (!singleLine.compare("&"))
			{
				stack.op("&");
			}
			else if (!singleLine.compare("|"))
			{
				stack.op("|");
			}
			else if (!singleLine.compare("!"))
			{
				stack.op("!");
			}
			else if (!singleLine.compare("<>"))
			{
				stack.op("<>");
			}
			else if (!singleLine.compare("<="))
			{
				stack.op("<=");
			}
			else if (!singleLine.compare(">="))
			{
				stack.op(">=");
			}
			else if (!singleLine.compare("<"))
			{
				stack.op("<");
			}
			else if (!singleLine.compare(">"))
			{
				stack.op(">");
			}
			else if (!singleLine.compare("=="))
			{
				stack.op("==");
			}
			else if (singleLine.find("label") == 0 || !singleLine.compare("")) {
				// just ignore
			}
			else { break; } // halt execution if anything else or 'halt'.
			singleLine = ""; // reset line
		}
		inputFile.close();
	}
	else
		cout << "Error: File is unable to open.  Check the location and the name of the file for possible errors.";
	


	// Wait for user to press 'Enter' to exit program
	outputFile.close();
	char WaitChar;

	cout << "\nProccessing finished. Press 'Enter' to exit the program: \n\n";
	cin.get(WaitChar);
	return 0;
}