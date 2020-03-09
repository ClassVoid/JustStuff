#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	int n,i,val;
	List *p;

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
/*	
	cout<<"pos=";
	cin>>pos;
	cout<<"val=";
	cin>>val;
	if(inpos(p,val,pos)==1)
	{
		afisare(p);
	}
	else
	{
		cout<<"pozitie inexistenta\n";
	}
	
	cout<<"delete pos=";
	cin>>pos;
	if(delpos(p,pos)==1)
	{
		afisare(p);
	}
	else
	{
		cout<<"pozitie inexistenta\n";
	}
*/
	frontBack(p);
	cout<<endl;
	if(loopCheck(p)==1)
	{
		cout<<"exista bucle\n";
	}
	else
	{
		cout<<"nu exista bucle\n";
	}
	
	cout<<"elementul din mijloc="<<manInTheMiddle(p)<<endl;
	ReDo(p);
	afisare(p);

	while(p!=0)
	{
		delet(p);
	}

	return 0;
}
