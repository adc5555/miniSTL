#ifndef VECTOR_H
#define VECTOR_H
#endif
#define NULL 0
/*
  Implement a simple vector
  Pass the test under the MinGW-w64 GCC 13.1.0
  Code:XKM
 */
template <typename T>
class vector
{
public:
	//rename for easier understanding
	typedef T value_type;
	typedef T* iterator;
	typedef unsigned long size_t;
private:
	value_type* data;
	size_t _size;//real _size
	size_t _capacity;//the space has been allocated
public:
	//init
	vector():data(NULL),_size(0),_capacity(0){}
	//init with copying the other vector
	vector(const vector& vec)
	{
		_size=vec._size;
		data=new value_type[_capacity];
		_capacity=vec._capacity;
		for(int i=0;i<_size;i++)
			data[i]=vec.data[i];
	}
	//free the memory in the end
	~vector()
	{
		delete [] data;
		data=NULL;
		_size=0;
		_capacity=0;
	}
	//overload the operations
	vector& operator=(const vector& vec)
	{
		if(this==vec) return *this;
		value_type *temp=new value_type[vec._capacity];
		for(int i=0;i<vec.__size;i++)
			temp[i]=vec.data[i];
		delete [] data;
		data=temp;
		_size=vec._size;
		_capacity=vec._capacity;
		return *this;
	}
	bool operator==(const vector& vec)const
	{
		if(_size!=vec._size) return false;
		for(int i=0;i<_size;i++)
			if(data[i]!=vec.data[i])
				return false;
		return true;
	}
	value_type& operator[](size_t pos)
	{
		return data[pos];
	}
	//push a variable at the end of the vector
	void push_back(value_type val)
	{
		if(_capacity==0)
		{
			_capacity=1;
			data=new value_type[1];
		}
		else if(_size+1>_capacity)
		{
			//request memory in a multiplication manner to reduce the number of times data is copied
			_capacity*=2;
			value_type *tmp=new value_type[_capacity];
			for(int i=0;i<_size;i++)
				tmp[i]=data[i];
			delete [] data;
			data=tmp;
		}
		data[_size++]=val;
	}
	void insert(iterator it,value_type val)
	{
		int pos=it-data;//the postion where the new value will be inserted
		if(0==_capacity)
		{
			_capacity=1;
			data=new value_type[1];
			data[0]=val;
		}else if(_size+1>_capacity)
		{
			_capacity*=2;//the function is same to the push_back
			value_type *tmp=new value_type[_capacity];
			for(int i=0;i<_size;i++)
				tmp[i]=data[i];
			tmp[pos]=val;
			for(int i=pos;i<_size;i++)
				tmp[i+1]=data[i];
			delete [] data;
			data=tmp;
		}
		else
		{
			for(int i=_size-1;i>=pos;i++)	
				data[i+1]=data[i];
			data[pos]=val;
		}
		_size++;
	}
	void pop_back()
	{
		_size--;
	}
	void erase(iterator it)
	{
		size_t pos=it-data;
		for(int i=pos;i<_size-1;i++)
			data[i]=data[i+1];
		_size--;
	}
	value_type front()const
	{
		return data[0];	
	}
	value_type back()const
	{
		return data[_size-1];
	}
	size_t size()const
	{
		return _size;
	}
	iterator begin(){ return data;}
	iterator end(){ return data+_size;}
	size_t capacity()const{
		return _capacity;
	}
	bool empty(){
		return _size == 0;
	}
};
