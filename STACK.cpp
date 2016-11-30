#include "STACK.h"

int STACK::size() const
{
	return max;
}

STACK::operator int() const
{
	return pos;
}

STACK& STACK::operator<<(int e)
{
	if (pos < max)
	{
		elems[pos++] = e;
	}
	return *this;
}

STACK& STACK::operator>>(int& e)
{
	if (pos > 0)
	{
		e = elems[--pos];
	}
	return *this;
}

void STACK::print() const
{
	int i = pos, j = 0;
	while (j != i)
	{
		cout << elems[j++] << ' ';
	}
}
