#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	Nod *r=0;
	int val;
	r = BuildTree();
	Inorder(r);
	cout<<endl;
	/*
	cout << "ce nod doriti sa stergeti?\n";
	cin >> val;
	DeleteNode(r, val);
	cout << endl;
	Inorder(r);
	*/
	PrintInd(r, 1);
	/*
	cout << "\nce valoare doriti sa cautati?\n";
	cin >> val;
	if (Search(r, val) == 0)
	{
		cout << "valoarea nu se gaseste\n";

	}
	else
	{
		cout << "valoarea este in graf\n";
	}
	*/
	Eliberare(r);
	return 0;
}
