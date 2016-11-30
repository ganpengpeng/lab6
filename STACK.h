#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class STACK {
	int  *const  elems;	//申请内存用于存放栈的元素
	const  int   max;	//栈能存放的最大元素个数
	int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
	//初始化栈：最多m个元素
	STACK(int m = 10) :elems(new int[m]), max(m), pos(0) { cout << "stack construct" << endl; }
	//用栈s拷贝初始化栈,深拷贝
	STACK(const STACK&s) :elems(new int[s.max]), max(s.max), pos(s.pos)
	{
		memcpy(this->elems, s.elems, sizeof(int)*s.max);
		cout << "stack copy construct" << endl;
	}
	//销毁栈
	virtual ~STACK()
	{
		elems == nullptr ? 0 : (delete elems, *const_cast<int**>(&elems) = nullptr);
		cout << "stack deconstruct" << endl;
	}
	virtual STACK& operator=(const STACK& other)
	{
		if (this == &other) return *this;//自赋值检查
		delete(elems);
		*const_cast<int**>(&elems) = new int[other.max];
		memcpy(elems, other.elems, sizeof(int)*other.max);
		*const_cast<int*>(&max) = other.max;
		pos = other.pos;
		return *this;
	}
	int  size() const;					//返回栈的最大元素个数max
	virtual operator int() const;			//返回栈的实际元素个数pos
	virtual STACK& operator<<(int e); 	//将e入栈,并返回栈
	virtual STACK& operator >> (int &e);	//出栈到e,并返回栈
	virtual void print() const;			//打印栈
	int getp() const { return pos; }
	int getm() const { return max; }
protected:
	int a;
};

