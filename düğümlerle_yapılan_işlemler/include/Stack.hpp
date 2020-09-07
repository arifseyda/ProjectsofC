#ifndef Stack_HPP
#define Stack_HPP
#include <iostream>
using namespace std;
class Stack
{
public:
	Stack();
	void stackelemanEkle(int);
	void stackYaz();
	void reserve(int);
	~Stack();
private:
	int *data;
	int top = 0;
	int capacity;
};
#endif
