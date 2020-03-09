#include <iostream>
#include "header1.h"
using namespace std;


char *Init(int n)
{
	char *a;
	a=new char[n+1];
	return a;
}
void Inordine(char *a,int n,int i)
{
	if(i<=n && (a[i]!='-'))
	{
		Inordine(a,n,i*2);
		cout<<a[i]<<" ";
		Inordine(a,n,i*2+1);
	}
}
void Insert(char *a,int &n,int val)
{	
	int fiu,father;
	a[n+1]=val;
	n=n+1;
	fiu=n;
	father=n/2;
	while(father>=1)
	{
		if(a[father] < a[fiu])
		{
			swap(a[father],a[fiu]);
			fiu=father;
			father/=2;
		}
		else
		{
			father=0;
		}
	}
}
char Remove(char *a,int &n)
{	
	int ret_val,father,fiu;

	if(n==0)
	{
		cout<<"erroare in fct remove\n";
	}
	else
	{
		ret_val=a[1];
		a[1]=a[n];
		n--;
		father=1;
		fiu=2;
		while(fiu<=n)
		{
			if(fiu+1 <= n && a[fiu] < a[fiu+1])
			{
				fiu++;
			}
			if(a[fiu]>a[father])
			{
				swap(a[father],a[fiu]);
				father=fiu;
				fiu*=2;
			}
			else
			{
				fiu=n+1;
			}
		}
	}
	return ret_val;
}
void BuildHeap(char *a,int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		Retro(a,n,i);
	}
}
void Retro(char *a,int n,int i)
{
	int father, fiu;
	father=i;
	fiu=2*i;
	while(fiu<=n)
	{
		if(fiu+1<=n && a[fiu]<a[fiu+1])
		{
			fiu++;
		}
		if(a[fiu]>a[father])
		{
			swap(a[father],a[fiu]);
			father=fiu;
			fiu*=2;
		}
		else
		{
			fiu=n+1;
		}
	}
}
void Swap(char &a,char &b)
{
	char aux;
	aux=a;
	a=b;
	b=aux;
}

