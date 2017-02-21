#include "stdafx.h"
#include "logical.h"
#include "stack_manipulation.h"

logical::logical()
{
}

void logical::logAnd()
{
	 int x = Stack::pop();
	 int y = Stack::pop();
	 Stack::push((x&&y));
}

void logical::logNeg()
{
	 int x = Stack::pop();
	 Stack::push((!x));
}

void logical::logOr()
{
	 int x = Stack::pop();
	 int y = Stack::pop();
	 Stack::push((x||y));
}


logical::~logical()
{
}
