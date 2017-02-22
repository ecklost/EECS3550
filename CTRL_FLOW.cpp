// Control Flow Instructions

#include "stdafx.h"
#include "CTRL_FLOW.h"
#include "stack_manipulation.h"
#include "SymbolTable.h"

CTRL_FLOW::CTRL_FLOW()
{
	
}

void CTRL_FLOW::getLabel()
{
	//if (parameter.length() == 0)
	//{
	//	cout << "Need a parameter in order to specify which label to retrieve." << endl;
	//	return;
	//}

}

void CTRL_FLOW::goTo()
{
	// Not quite sure how to approach this
/*	if (labelChar.length() > 0)
	{
		if (SymbolTable::SymbolTable.length())
		{
			// Get the next instruction in the symbol table?
		}
		else
		{
			cout << "Label [...] does not exist in the file." << endl;
		}
	}
	else
	{
		cout << "The goTo method must include a value." << endl;
	}*/

}

void CTRL_FLOW::goFalse()
{
	//if (stack.size() == 0)
	//{
	//	cout << "Stack is empty, therefore there is nothing to check" << endl;
	//	return;
	//}

	//if (stack.top() == 0)
	//{
	//	getLabel();
	//}

	//stack.pop();
}

void CTRL_FLOW::goTrue()
{
	//if (stack.size() == 0)
	//{
	//	cout << "Stack is empty, therefore there is nothing to check" << endl;
	//	return;
	//}

	//if (stack.top() == 1)
	//{
	//	getLabel();
	//}

	//stack.pop();
}

void CTRL_FLOW::halt()
{
	//return 0;
}


CTRL_FLOW::~CTRL_FLOW()
{
}