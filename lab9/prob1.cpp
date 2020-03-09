#include <iostream>
#include <cstring>
#include "header1.h"
using namespace std;

int main()
{
	char s[128];
	int nr=0,i=0,dim,var;
	bool flag=0;
	Nod *r=0;

	cout<<"introduceti sirul\n";
	cin.getline(s,128);
	dim=(int)strlen(s);
	cout<<"dim="<<dim<<endl;
	while(i<dim  && flag!=1)
	{
		//cout<<i<<" iteratii\n";
		if(i>0 && s[i]==' ' && s[i-1]!=' ' && nr!=0)
		{
			//il pui in graf
			insert(r,nr);
			cout<<nr<<" ";
			nr=0;
		}
		else
		{
			if(i>0 && s[i-1]==' ' && s[i]=='0')
			{
				flag=1;
				//cout<<"flag="<<flag<<endl;
			}
			else
			{
				if(s[i]>='0' && s[i]<='9')
				{
					nr=nr*10+(s[i]-'0');
				}
			}
		}
		i++;
	}


	cout<<"\nafisare in inordine"<<endl;

	inordine(r);
	cout<<"\nintroduceti o variabila pt a o cauta\n";
	cin>>var;
	if(search(r,var)==0)
	{
		cout<<"variabila nu se gaseste in graf\n";
	}
	else
	{
		cout<<"variabila este in graf\n";
	}

	return 0;
}
