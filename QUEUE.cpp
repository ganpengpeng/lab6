#include "queue.h"

QUEUE::QUEUE(int m) : s2(m)
{
	cout << "queue construct" << endl;
}

QUEUE::QUEUE(const QUEUE& s) : s2(s.s2)
{
	cout << "queue copy construct" << endl;
}

QUEUE::operator int() const
{
	return s1.getp() + s2.getp();
}

QUEUE& QUEUE::operator<<(int e)
{
	if (s1.getp() >= s1.getm() && s2.getp() == 0)
	{
		while (s1.getp() != 0)
		{
			int x;
			s1 >> x;
			s2 << x;
		}
	}
	s1.getp() >= s1.getm() ? 0 : s1 << e;
	return *this;
}

QUEUE& QUEUE::operator >> (int& e)
{
	if (s1.getp() != 0 && s2.getp() == 0)
	{
		while (s1.getp() != 0)
		{
			int x;
			s1 >> x;
			s2 << x;
		}
	}
	s2.getp() > 0 ? s2 >> e : 0;
	return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& s)
{
	s1 = s.s1;
	s2 = s.s2;
	return *this;
}

void QUEUE::print() const
{
	STACK temp = s2;
	for (int i = temp.getp(); i != 0; --i)
	{
		int x;
		temp >> x;
		cout << x << ' ';
	}
	s1.print();
	cout << endl;
}

QUEUE::~QUEUE()
{
	cout << "queue deconstruct" << endl;
}
