#include <iostream>
#include <cstring>
#include "header1.h"

using namespace std;

int functie(char *s,int n)
{
	int i=0,suma=0;
//ai putea avea probleme
	while(s[i]!='\0')
	{
		suma+=s[i];
		i++;
	}
	return suma % n;
}
Nod** init(int n)//n e numarul de elemente
{
	int i;
	Nod **ht=0;

	ht=new Nod*[n];

	for(i=0;i<n;i++)
	{
		ht[i]=0;
	}
	return ht;
}
bool search(Nod **ht,char *s,int n)
{
	int index;
	Nod *p;

	index=functie(s,n);
	p=ht[index];
	while(p!=0)
	{
		if(strcmp(s,p->s)==0)
		{
			return 1;
		}
		p=p->leg;
	}
	return 0;
}
void insert(Nod **ht,char *s,int n)
{
	Nod *p=0;
	int index;

	if(search(ht,s,n)==0)
	{
		p=new Nod;
		p->s=new char[strlen(s)];
		strcpy(p->s,s);
		index=functie(s,n);
		//lipire
		p->leg=ht[index];
		ht[index]=p;
	}
}
void listare(Nod **ht,int n)
{
	int i;
	Nod *p;

	for(i=0;i<n;i++)
	{
		p=ht[i];
		cout<<"linia "<<i<<" : ";
		while(p!=0)
		{
			cout<<p->s<<" ";
			p=p->leg;
		}
		cout<<endl;
	}
}
