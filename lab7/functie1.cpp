#include <iostream>
#include <cstring>
#include "header1.h"
using namespace std;

ELEM **InitHT(int n)
{
	ELEM **ht;
	ht=new ELEM*[n];
	for(int i=0;i<n;i++)
	{
		ht[i]=0;
	}
	return ht;
}

int fc(char *sir)
{
	int tot=0;

	for(int i=0;i<(int)strlen(sir);i++)
	{
		tot+=(int)sir[i];
	}
	tot=tot%M;
	return tot;
}

ELEM *SearchHT(ELEM **ht,char *sir)
{
	int index=fc(sir);
	ELEM *p;
	p=ht[index];

	while(p!=0)
	{
		if(strcmp(p->sir,sir)==0)
		{
			return p;
		}
		p=p->urm;
	}
	return 0;
}

bool InsertHT(ELEM **&ht,char *sir)
{
	int index=fc(sir);
	ELEM *p=0;
	if(ht[index]==0)
	{
		p=new ELEM;
		p->sir=new char[strlen(sir)+1];
		strcpy(p->sir,sir);
		p->urm=0;
		ht[index]=p;
		return 1;
	}
	else
	{
		if(SearchHT(ht,sir)==0)
		{
			p=new ELEM;
			p->sir=new char[strlen(sir)+1];
			strcpy(p->sir,sir);
			p->urm=ht[index];
			ht[index]=p;
			return 1;
		}
	}
	return 0;

}

void afis(ELEM *cap)
{
	
	while(cap)
	{
		cout<<cap->sir<<"# ";
		cap=cap->urm;
	}
	cout<<"\n";
}

void sterg(ELEM **&ht)
{
	int i;
	ELEM *p;

	for(i=0;i<M;i++)
	{
		while(ht[i])
		{
			p=ht[i];
			ht[i]=ht[i]->urm;
			delete p->sir;
			delete p;
		}
	}
	delete ht;
}
