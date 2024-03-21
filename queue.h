/*
Implement a simple priority_queue
Pass the test under the MinGW-w64 GCC 8.1.0 32-bit
Code:XKM
*/
#include"vector.h"
#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class priority_queue
{
public:
	typedef T value_type;
	typedef T* iterator;
	typedef unsigned long size_t;
private:
	vector<T> vec;
	size_t _size;
	void swap(T &a,T &b)
	{
		value_type c;
		c=a;
		a=b;
		b=c;
	}
public:
	priority_queue()
	{
		value_type nil;
		vec.push_back(nil);
		_size=0;
	}
	void push(value_type x)
	{
		vec.push_back(x);
		size_t pos =++_size;
		while(pos>1)
		{
			size_t nxt=pos>>1;
			if(vec[nxt]<vec[pos])
				swap(vec[nxt],vec[pos]);
			else break;
			pos=nxt;
		}
		return;
	}
	void pop()
	{
		swap(vec[1],vec[_size--]);
		vec.pop_back();
		size_t pos=1;
		while((pos<<1)<=_size)
		{
			size_t nxt=pos<<1;
			if(nxt+1<=_size&&vec[nxt]<vec[nxt+1]) nxt++;
			if(vec[pos]<vec[nxt]) swap(vec[pos],vec[nxt]);
			else break;
			pos=nxt;
		}
	}
	value_type top()
	{
		return vec[1];
	}
	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size==0? true:false;
	}
	
	
};
#endif
