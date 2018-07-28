
#ifndef bst_H_
#define bst_H_

#include "treeNode.h"

//Binary Search Tree Top Level Class
class bst
{
	private:
		treeNode *root;

	public:
		bst();
		~bst();

		treeNode *getroot();	//Getter for root

		void insert(char word[11], treeNode *node, int linenum);	//Method for adding a new word to the tree
		void displaytree(treeNode *node);	//Displays the contents of the tree as a cross-reference index
		void freetree(treeNode *node);		//Deallocates all memory used by the tree
};

#endif