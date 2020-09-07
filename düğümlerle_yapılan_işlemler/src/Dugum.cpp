#include "Dugum.hpp"
#include "Stack.hpp"
#include <iostream>
	Node::Node(int sayi){
		dizim = new Stack();
		Data = sayi;
		dizim->stackelemanEkle(sayi);
	}
	void Node::kaydir(int sayi) {
		Data = sayi;
		dizim->stackelemanEkle(sayi);
	}
	Node* Node::getPnext()
	{
		return pNext;
	}
	Node* Node::getPprev()
	{
		return pPrev;
	}
	
	int Node::getData()
	{
		return Data;
	}
	int Node::setData(int sayi)
	{
		Data = sayi;
		return Data;
	}
	void Node::setPnext(Node *pnext)
	{
		pNext = pnext;
	}
	void Node::setPrev(Node *pprev)
	{
		pPrev = pprev;
	}
	void Node::dugumYaz()
	{
		dizim->stackYaz();
	}
	Node::~Node()
	{
		delete pNext;
		delete pPrev;
		delete[] dizim;
	}