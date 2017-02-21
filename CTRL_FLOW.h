#pragma once

class CTRL_FLOW
{
public:
	CTRL_FLOW();
	void getLabel();
	void goTo();
	void goFalse();
	void goTrue();
	void halt();
	~CTRL_FLOW();
};