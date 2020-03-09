#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	Queue q;
	int i,n,val;
	init(q);

	cout<<"n=";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"val=";
		cin>>val;
		put(q,val);
	}

	while(!isEmpty(q))
	{
		val=get(q);
		cout<<val<<" ";
	}


	return 0;
}
