#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	int n=0,i,val,nn;
	int a[DIM];

	cout<<"numar de elemente = ";
	cin>>nn;
	n=nn;
	for(i=1;i<=nn;i++)
	{
		cout<<"val=";
		cin>>a[i];
	}
//	inordine(a,n);

	buildHeap(a,n);
	inordine(a,n);

	while(n>0)
	{
		val=remove(a,n);
		cout<<val<<" ";
	}
	cout<<endl;

	return 0;
}

