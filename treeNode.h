
#ifndef treeNode_H_
#define treeNode_H_

#include "lineNum.h"


//Class for the tree nodes for the binary search tree
class treeNode
{

	private:
		treeNode *right;	//Right subtree
		treeNode *left;		//Left subtree
		lineNum *head;		//Head of list of line numbers

	public:
		treeNode();
		~treeNode();

		char word[11];		//Word of 10 chars + null terminator
		
		void setright(treeNode *input);
		void setleft(treeNode *input);
		treeNode *getright();
		treeNode *getleft();
		lineNum *gethead();

		void insertNum(int num);	//Method for inserting new line num into sorted list
		void freelist();			//Frees the list of line numbers form memory
};

#endif