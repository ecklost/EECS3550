#pragma once
// delete, use is in stack manipulation
class SUBPROGRAM_CTRL
{
public:
	SUBPROGRAM_CTRL();
	void begin();
	void end();
	void ret();
	void call();
	~SUBPROGRAM_CTRL();
};