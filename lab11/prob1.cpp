#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	int n,i,nn=0;
	char *a,x;

	cout<<"n= ";
	cin>>n;
	a=Init(n);
	
	
	for(i=1;i<=n;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>x;
		Insert(a,nn,x);
	}
	BuildHeap(a,n);
	cout<<endl<<"vector"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	i=1;
	Inordine(a,nn,i);

	delete a;
	return 0;
}
