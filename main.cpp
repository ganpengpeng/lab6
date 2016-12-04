#include "queue.h"
void printhead();
int main()
{
	int circle = 1;
	const int m = 10;
	QUEUE s;
	QUEUE p;
	for (int i = 0; i < m; ++i)
	{
		s << i;
	}
	while (circle != 0)
	{
		system("cls");
		printhead();
		cin >> circle;
		switch (circle)
		{
		case 0:
		{
			cout << "Quit" << endl;
			break;
		}
		case 1:
		{
			QUEUE p;
			break;
		}
		case 2:
		{
			QUEUE p = s;
			break;
		}
		case 3:
		{
			cout << "currentsize:" << int(p) << endl;
			break;
		}
		case 4:
		{
			int e = INT_MIN;
			cout << "input a num:";
			cin >> e;
			p << e;
			break;
		}
		case 5:
		{
			int e = INT_MIN;
			p >> e;
			if (e != INT_MIN) cout << "dequeue " << e << endl;
			break;
		}
		case 6:
		{
			p = s;
			break;
		}
		case 7:
		{
			p.print();
			break;
		}
		default: break;
		}
		system("pause");
		if (circle == 0) break;
	}
	return 0;
}
void printhead()
{
	cout << "        C++ Queue" << endl;
	cout << "1.init         " << "2.init with another stack" << endl;
	cout << "3.int(p)       " << "4.operator<<" << endl;
	cout << "5.operator>>   " << "6.operator=" << endl;
	cout << "7.print        " << "0.quit" << endl;
}