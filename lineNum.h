
#ifndef lineNum_H_
#define lineNum_H_

//Class for linked list of line numbers 
class lineNum
{
	private:
		int num;
		lineNum *next;

	public:
		lineNum();
		~lineNum();

		void setnum(int input);
		void setnext(lineNum *input);
		int getnum();
		lineNum *getnext();
};

#endif