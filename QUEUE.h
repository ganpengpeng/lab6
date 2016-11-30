#pragma once
#include "STACK.h"

class QUEUE :public STACK {
	STACK  s2;
public:
	QUEUE(int m=10);		//��ʼ�����У����m��Ԫ��
	QUEUE(const QUEUE&s); 		//�ö���s������ʼ������
	operator int() const override;	//���ض��е�ʵ��Ԫ�ظ���pos
	QUEUE& operator<<(int e) override; 		//��e�����,�����ض���
	QUEUE& operator >> (int &e) override;	//�����е�e,�����ض���
	QUEUE& operator=(const QUEUE&s); //��s������,�����ر���ֵ�Ķ���
	void print() const override;			//��ӡ����
	~QUEUE();					//���ٶ���
};
