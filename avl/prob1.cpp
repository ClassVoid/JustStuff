#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	int n,i,val;
	AVL *r=0;

	cout<<"n=";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"val=";
		cin>>val;
		insert(r,val);
	}
	afisare(r);
	cout<<endl;

	deletAll(r);

	return 0;
}
