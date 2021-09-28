#pragma once
#include<iostream>
#include<fstream>

using namespace std;
class POLYN
{
	int deg;
	int* cs;

public:
	POLYN(void);
	void setval(ifstream& Read);
	void print() const;


 void Add(const POLYN& P2,POLYN& P3)
{
	cout << endl;
	P3.cs = new int[deg + 1];
	P3.deg = (deg > P2.deg) ? deg : P2.deg;
	//P3.deg = deg;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int i = 0;
	do{
		if (i == P2.deg + 1 || i > P2.deg + 1)
		{
			P3.cs[i] = cs[i] + 0;
		}
		else
		{
			P3.cs[i] = this->cs[i] + P2.cs[i];
		}
		i++;
	} while (i <= P3.deg);
}

 void Sub(const POLYN& C2, POLYN& P3)
 {
	 cout << endl;
	 P3.cs = new int[deg + 1];
	 P3.deg = deg;
	 int i = 0; 
	 {
		 if (i == C2.deg + 1 || i > C2.deg + 1)
		 {
			 P3.cs[i] = cs[i] + 0;
		 }
		 else
		 {
			 P3.cs[i] = cs[i] - C2.cs[i];
		 }
		 i++;
	 }while (i <= deg);
 }



 void Mult(const POLYN& C2, POLYN& P3)
 {
	 int d = deg + C2.deg + 1;
	 P3.cs = new int[d];
	 P3.deg = d - 1;
	 int k = 0; 
	 do{
		 P3.cs[k] = 0;
		 k++;
	 } while (k < d);

		 int i = 0;
	 do{
		 int k = 0;

		 do{
			 int a, b;
			 a = P3.cs[i + k] + cs[i];
			 b=C2.cs[k];
			 P3.cs[i + k] = a + b;

			 k++;
		 } while (k < C2.deg);

		 i++;
	 } while (i < deg);

 }



};