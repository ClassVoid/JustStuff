#include <iostream>
#include "header2.h"
using namespace std;

int main()
{
	List *p;
	int n,i,val,pos;

	cout<<"n=";
	cin>>n;
	init(p);

	for(i=0;i<n;i++)
	{
		cout<<"Lsit=";
		cin>>val;
		insert(p,val);
	}
	afisare(p);

	cout<<"pos=";
	cin>>pos;
	delpos(p,pos);
	afisare(p);

	return  0;
}
