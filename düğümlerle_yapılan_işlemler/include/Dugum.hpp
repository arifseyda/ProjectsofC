#ifndef Dugum_HPP
#define Dugum_HPP
#include <iostream>
#include "Stack.hpp"
using namespace std;
class Node
{
    private:
	Node *pNext=NULL;
	Node *pPrev=NULL;
	int Data;
	Stack *dizim;
public:
	Node(int);
	void kaydir(int);
	Node *getPnext();
	Node *getPprev();
	int getData();
	int setData(int);
	void setPnext(Node *pnext);
	void setPrev(Node *pprev);
	void dugumYaz();
	~Node();
};
#endif