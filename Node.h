#pragma once
#include"iostream"
using namespace std;
template<typename T>

class node
{
private:
	T item;
	node* next;

public:
	node()
	{
		setnext(NULL);
	}

	node(T i)
	{
		item = i;
	}

	node(T i, node* ptr)
	{
		item = i;
		next = ptr;
	}

	void setitem(const T& i)
	{
		item = i;
	}

	void setnext(node* nextptrpoiner)
	{
		next = nextptrpoiner;
	}

	T getitem() const
	{
		return item;
	}

	node* getnext() const
	{
		return next;
	}

};