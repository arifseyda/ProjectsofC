#include "Stack.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
	Stack::Stack()
	{
		data = NULL;
		top=-1;
		capacity = 0;
	}
	void Stack::reserve(int newCapacity)
	{
		int *tmp = new int[newCapacity];
		
		for(int i = 0; i < (top + 1); i++)
		{
			tmp[i] = data[i];
		}
		if(data != NULL) delete [] data;
		data = tmp;
		capacity = newCapacity;
	}
	void Stack::stackelemanEkle(int sayi)
	{
		if((top + 1) == capacity)
			reserve(max(1,2*capacity));
		data[++top] = sayi;
	}
	void Stack::stackYaz()
	{
		for (int i = top; i >= 0; i--)
		{
			cout << setw(4) << ":" <<setw(10)<< data[i] ;
		}
	}
	Stack::~Stack()
	{
		delete data;
	}
	