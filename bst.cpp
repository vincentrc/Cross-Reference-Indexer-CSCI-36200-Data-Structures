
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "bst.h"
#include "treeNode.h"



bst::bst()
{
	this->root = NULL;
}

bst::~bst(){}

treeNode *bst::getroot()
{
	return this->root;
}


//Method for inserting a new word into the tree
void bst::insert(char word[11], treeNode *node, int linenum)
{
	treeNode *newnode;
	int x;

	//If there is no match currently, insert new node at first NULL
	if(this->root == NULL)
	{
		newnode = new treeNode();
		strcpy(newnode->word, word);
		newnode->insertNum(linenum);
		this->root = newnode;
		return;
	}

	//Compares new word to root word 
	x = strcmp(node->word, word);

	//If the words are a match
	if(x == 0)
	{
		node->insertNum(linenum);
		return;
	}

	//If the new word is lower, call for left subtree
	else if(x > 0)
	{
		if(node->getleft() == NULL)
		{
			newnode = new treeNode();
			strcpy(newnode->word, word);
			newnode->insertNum(linenum);
			node->setleft(newnode);
			return;
		}

		insert(word, node->getleft(), linenum);
	}

	//Otherwise call for right subtree
	else
	{
		if(node->getright() == NULL)
		{
			newnode = new treeNode();
			strcpy(newnode->word, word);
			newnode->insertNum(linenum);
			node->setright(newnode);
			return;
		}

		insert(word, node->getright(), linenum);
	}
}

//Displays the tree as a cross-reference index using inorder traversal
void bst::displaytree(treeNode *node)
{
	lineNum *ptr;
	FILE *fp;

	//If found the bottom of a subtree
	if(node == NULL)
		return;

	//Traverses left subtree first
	displaytree(node->getleft());

	//Opens file stream for writing to output file
	if((fp = fopen("index.txt", "a")) == NULL)
		perror("Error");

	//Then displays the node contents
	printf("\n%-10s   ",node->word);
	fprintf(fp, "\n%-10s   ",node->word);

	for(ptr = node->gethead(); ptr != NULL; ptr = ptr->getnext())	//This iterates through the list of line numbers
	{
		std::cout << ptr->getnum() << "    ";
		fprintf(fp, "%d   ", ptr->getnum());
	}

	std::cout << "\n";
	fprintf(fp, "\n");

	if(fclose(fp) != 0)		//Closes file stream
		perror("Error");

	//Then traverses right subtree
	displaytree(node->getright());
}

//Deallocates all memory used by the tree using postorder traversal
void bst::freetree(treeNode *node)
{
	//Finds the bottom 
	if(node == NULL)
		return;

	//Traverses left subtree first
	freetree(node->getleft());

	//Then right
	freetree(node->getright());

	//Deletes each node
	node->freelist();
	delete node;
}



