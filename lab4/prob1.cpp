#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	List *p;
	int n,i,val,pos;

	init(p);
	cout<<"n=";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"list=";
		cin>>val;
		insert(p,val);
	}
	afisare(p);
	cout<<"stergere\npos=";
	cin>>pos;
	delpos(p,pos);
	afisare(p);


	return 0;
}
