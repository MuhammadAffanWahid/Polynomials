#include "POLYN.h"
#include<iostream>
#include<windows.h>


using namespace std;
void color(int k)

{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

POLYN::POLYN()
{
	this->deg = 0;
	this->cs = nullptr;
}

void POLYN::setval(ifstream& read)
{
	read >> deg;
	cs = new int[deg + 1];
	for (int i = 0; i < deg + 1; i++)
	{
		read >> cs[deg - i];
	}
}

void POLYN::print() const
{	
	int  i = this->deg;
	while (i>=0)
	{
		if (cs[i] != 0)
		{
			color(15);
			cout << ((cs[i] > 0 && i != deg) ? "+" : "");
			color(10);
			cout << cs[i];
			if (i != 0)
			{
				color(9);
				cout << "X";
				color(13);
				cout << "^";
				color(12);
				cout << i;
			}
		}

		i--;
	}
}