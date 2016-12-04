#include "queue.h"

QUEUE::QUEUE(int m) : STACK(m), s2(m)
{
	cout << "queue construct" << endl;
}

QUEUE::QUEUE(const QUEUE& s) : STACK(s), s2(s.s2)
{
	cout << "queue copy construct" << endl;
}

QUEUE::operator int() const
{
	return STACK::operator int() + int(s2);
}

QUEUE& QUEUE::operator<<(int e)
{
	if (STACK::operator int() >= size() && int(s2) == 0)
	{
		while (STACK::operator int() != 0)
		{
			int x;
			STACK::operator >> (x);
			s2 << x;
		}
	}
	if(STACK::operator int() < size())
		STACK::operator  << (e);
	return *this;
}

QUEUE& QUEUE::operator >> (int& e)
{
	if (STACK::operator int() != 0 && int(s2) == 0)
	{
		while (STACK::operator int() != 0)
		{
			int x;
			STACK::operator >> (x);
			s2 << x;
		}
	}
	if (s2 > 0)
		s2 >> e;
	//int(s2) > 0 ? s2 >> e : 0;
	return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& s)
{
	STACK::operator=(s);
	s2 = s.s2;
	return *this;
}

void QUEUE::print() const
{
	STACK temp = s2;
	for (int i = int(temp); i != 0; --i)
	{
		int x;
		temp >> x;
		cout << x << ' ';
	}
	STACK::print();
	cout << endl;
}

QUEUE::~QUEUE()
{
	cout << "queue deconstruct" << endl;
}
