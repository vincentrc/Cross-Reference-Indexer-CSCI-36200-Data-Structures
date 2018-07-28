
#include <iostream>
#include "lineNum.h"



lineNum::lineNum()
{
	this->next = NULL;
}

lineNum::~lineNum(){}

//Setters
void lineNum::setnext(lineNum *input)
{
	this->next = input;
}

void lineNum::setnum(int input)
{
	this->num = input;
}

//Getters
lineNum *lineNum::getnext()
{
	return this->next;
}

int lineNum::getnum()
{
	return this->num;
}

