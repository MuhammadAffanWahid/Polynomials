#include<iostream> 
#include<fstream> 
using namespace std;
#include<windows.h>
#include "POLYN.h"


void coolor(int k)

{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}
//
//void Readpoly(int& poly_size, POLYN*& polynomials, const char* FN)
//{
//	ifstream read(FN);
//	read >> poly_size;
//	polynomials = new POLYN[poly_size];
//	
//	for (int i = 0; i < poly_size; i++)
//	{
//		polynomials[i].setval(read);
//		i++;
//	}
//}

//void LoadPolynomials(const char* FileName, int& PSize, POLYN*& Ps)
//{
//	ifstream Rdr(FileName); Rdr >> PSize;
//	Ps = new POLYN[PSize];
//	int pi = 0;
//	do{
//		Ps[pi].setval(Rdr);
//
//		pi++;
//	} while (pi < PSize);
//}

void PrintPolys(POLYN* polynomials , int poly_size)
{
	int i = 0;
	do{
		coolor(10);
		cout << "P" << (i + 1);
		coolor(1);
		cout << " =  ";
		polynomials[i].print();
		cout << endl;
		cout << endl;
			i++;
	} while (i < poly_size);

}


int main()
{
	int poly_size;
	POLYN* polynomials = nullptr;
	LoadPolynomials("data.txt", poly_size, polynomials);
	PrintPolys(polynomials, poly_size);

	POLYN P3;

	char d, opr;
	int r1, r2;
	cin >> d >> r1 >> opr >> d >> r2;

	switch (opr)
	{
	case'+':
		polynomials[r1 - 1].Add(polynomials[r2 - 1], P3);
		P3.print();
		cout << endl;
		break;
	case'-':
		polynomials[r1 - 1].Sub(polynomials[r2 - 1], P3);
		P3.print();
		cout << endl;
		break;
	case'*':
		polynomials[r1 - 1].Mult(polynomials[r2 - 1], P3);
		P3.print();
		cout << endl;
		break;
	}
	return 0;

}