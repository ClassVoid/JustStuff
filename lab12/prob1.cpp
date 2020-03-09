#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	bnod *r=0;
	int i,n=6;
	
	createBTree(r);
//inserare
	for(i=0;i<n;i++)
	{
		insertBTree(r,i);
	}

//afisare
	
	cout<<"\ninorder\n";
	Inorder(r);
	cout<<"\ndisplay\n";
	display(r,1);
	cout<<"r->tip="<<r->tip;


	return 0;
}
