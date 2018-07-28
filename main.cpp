
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include "bst.h"

int main()
{
	//Declarations
	std::string filename, line, temp, sub;
	int linenum = 1, flag =0;
	std::string::iterator i;
	char c, word[11];
	bst *tree = new bst();	//Instantiates a binary search tree
	std::ofstream output;

	//Erases the output file if it exists
	output.open("index.txt", std::ofstream::trunc);
	output.close();

	//Resets the screen to look neater (Unix)
	std::cout << "\033[H\033[2J";
	std::cout << "Please enter the name of the text file you wish to cross reference:\n";
	
	std::getline(std::cin, filename);
	std::ifstream ifs(filename); //Opens input stream to file

	//Prints error and exits if file doesn't exist 
	if(!ifs.is_open())
	{
		perror("Error");
		return 0;
	}
	
	//Takes in the text line by line to keep track of line number
	while(std::getline(ifs, line))
	{
		//Iterates through the line char by char 
		for(i = line.begin();i != line.end(); i++)
		{
			c = *i;

			if(((c >= 97) && (c <= 122)) || ((c>= 48) && (c <= 57))) //Checks to see if an alphanumerical character
				temp += c;	//Appends char to temp string

			else	//If not, finalize word, add to tree, and start with new string
			{
				if(temp.empty()) //Skips if nothing in temp string
					continue;

				sub = temp.substr(0,10);	//Creates a 10 char substring of temp starting at first char
				strcpy(word, sub.c_str());	//Copies the substring into a c string
				temp.clear();				//Clears the temp string to start new word

				if((word[0] < 'a') || (word[0] > 'z'))	//Skips if the word doesn't start with a letter
					continue;

				tree->insert(word, tree->getroot(), linenum);	//Inserts the word into the tree 
			}

		}

		//Checks to see if there is one last word before going to next line
		if(!temp.empty())
		{
			sub = temp.substr(0,10);	//Creates a 10 char substring of temp starting at first char
			strcpy(word, sub.c_str());	//Copies the substring into a c string
			temp.clear();		//Clears the temp string to start new word

			if(!((word[0] < 'a') || (word[0] > 'z')))	//Skips if the word doesn't start with a letter
					tree->insert(word, tree->getroot(), linenum);	//Inserts the word into the tree 
		}

		linenum++;
	}

	std::cout << "\n\n";
	tree->displaytree(tree->getroot());
	std::cout << "\n\n";

	tree->freetree(tree->getroot());
	delete tree;
	ifs.close();
	return 0;
}