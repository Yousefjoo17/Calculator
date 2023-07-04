#pragma once
#include"Node.h"

template<typename T>

class stack  //last in first out
{
private:
	node<T>* top;

public:

	stack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		if (!top)
			return true;
		return false;
	}

	void push(T value)
	{
		node<T>* ptr = new node<T>(value);
		node<T>* temp = top;
		top = ptr;
		ptr->setnext(temp);
	}

	T pop()
	{
		if (!top)
			return "0";
		T myitem = top->getitem();

		node<T>* temp = top;
		top = top->getnext();
		delete temp;

		return myitem;

	}

	T peek()
	{
		if (!top)
		{
			cout << "stack underflow";
			return "0";
		}
		return top->getitem();
	}

	void dispaly()
	{
		if (!top)
		{
			cout << "stack underflow" << endl;
			return;
		}
		node<T>* ptr = top;
		while (ptr)
		{
			cout << ptr->getitem() << " ";
			ptr = ptr->getnext();
		}
		cout << endl;
	}

	stack<T>& operator=(stack<T>& mother)
	{
		stack<int>stemp;

		while (!mother.isEmpty())
		{
			stemp.push(mother.peek());
			this->push(mother.pop());
		}

		while (!this->isEmpty())
			mother.push(this->pop());

		while (!stemp.isEmpty())
			this->push(stemp.pop());

		return *this;
	}
};