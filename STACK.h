#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class STACK {
	int  *const  elems;	//�����ڴ����ڴ��ջ��Ԫ��
	const  int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
	int   pos;			//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
	//��ʼ��ջ�����m��Ԫ��
	STACK(int m = 10) :elems(new int[m]), max(m), pos(0) { cout << "stack construct" << endl; }
	//��ջs������ʼ��ջ,���
	STACK(const STACK&s) :elems(new int[s.max]), max(s.max), pos(s.pos)
	{
		memcpy(this->elems, s.elems, sizeof(int)*s.max);
		cout << "stack copy construct" << endl;
	}
	//����ջ
	virtual ~STACK()
	{
		elems == nullptr ? 0 : (delete elems, *const_cast<int**>(&elems) = nullptr);
		cout << "stack deconstruct" << endl;
	}
	virtual STACK& operator=(const STACK& other)
	{
		if (this == &other) return *this;//�Ը�ֵ���
		delete(elems);
		*const_cast<int**>(&elems) = new int[other.max];
		memcpy(elems, other.elems, sizeof(int)*other.max);
		*const_cast<int*>(&max) = other.max;
		pos = other.pos;
		return *this;
	}
	int  size() const;					//����ջ�����Ԫ�ظ���max
	virtual operator int() const;			//����ջ��ʵ��Ԫ�ظ���pos
	virtual STACK& operator<<(int e); 	//��e��ջ,������ջ
	virtual STACK& operator >> (int &e);	//��ջ��e,������ջ
	virtual void print() const;			//��ӡջ
	int getp() const { return pos; }
	int getm() const { return max; }
protected:
	int a;
};

