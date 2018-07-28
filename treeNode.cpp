
#include <iostream>
#include "treeNode.h"
#include "lineNum.h"


treeNode::treeNode()
{
	this->head = NULL;
	this->left = NULL;
	this->right = NULL;
}

treeNode::~treeNode(){}

//Setters
void treeNode::setleft(treeNode *input)
{
	this->left = input;
}

void treeNode::setright(treeNode *input)
{
	this->right = input;
}

//Getters
treeNode *treeNode::getleft()
{
	return this->left;
}

treeNode *treeNode::getright()
{
	return this->right;
}

lineNum *treeNode::gethead()
{
	return this->head;
}


//Method for adding a new new line number to the sorted list 
void treeNode::insertNum(int num)
{
	lineNum *newnum = new lineNum();
	lineNum *ptr;

	newnum->setnum(num);	//Sets the number attribute

	//If there is nothing in the list
	if(this->head == NULL)
	{
		this->head = newnum;
		this->head->setnext(NULL);
		return;
	}
	
	//Otherwise
	else
	{
		ptr = head;

		//Sets ptr to end of list
		while(ptr->getnext() != NULL)
		{
			ptr = ptr->getnext();
		}

		//Adds the new number to the list
		ptr->setnext(newnum);
		newnum->setnext(NULL);
	}
}

//Frees the list of lie numbers from memory
void treeNode::freelist()
{
	lineNum *ptr, *temp;

	ptr = this->head;

	while(ptr != NULL)
	{
		temp = ptr;
		ptr = ptr->getnext();
		delete temp;
	}

}
