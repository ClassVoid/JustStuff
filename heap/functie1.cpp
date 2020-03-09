#include <iostream>
#include "header1.h"
using namespace std;

void insert(int *a,int val,int &n)
{
	int fiu,parinte;
	
	if(n<DIM)
	{
		a[n+1]=val;
		n++;
		fiu=n;
		parinte=n/2;
		while(parinte >= 1)
		{
			if(a[parinte] < a[fiu])
			{
				a[parinte]+=a[fiu];
				a[fiu]=a[parinte]-a[fiu];
				a[parinte]-=a[fiu];
				fiu=parinte;
				parinte/=2;
			}
			else
			{
				parinte=0;
			}
		}
	}
}
void inordine(int *a,int n)
{
	int i;

	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int remove(int *a,int &n)
{
	int val=0,fiu,parinte;

	if(n==0)
	{
		cout<<"error\n";
	}
	else
	{
		val=a[1];
		a[1]=a[n];
		n--;
		parinte=1;
		fiu=2;
		while(fiu<=n)
		{
			if((fiu+1 <= n) && (a[fiu] < a[fiu+1]))
			{
				fiu++;
			}
			if(a[fiu] > a[parinte])
			{
				a[parinte]+=a[fiu];
				a[fiu]=a[parinte]-a[fiu];
				a[parinte]-=a[fiu];
				parinte=fiu;
				fiu*=2;
			}
			else
			{
				fiu=n+1;
			}
		}
	}
	return val;
}
void retro(int *a,int n,int i)
{
	int parinte,fiu;

	parinte=i;
	fiu=2*i;

	while(fiu<=n)
	{
		if((fiu+1 < n) && (a[fiu] < a[fiu+1]))
		{
			fiu++;
		}
		if(a[fiu] > a[parinte])
		{
			a[parinte]+=a[fiu];
			a[fiu]=a[parinte]-a[fiu];
			a[parinte]-=a[fiu];
			parinte=fiu;
			fiu*=2;
		}
		else
		{
			fiu=n+1;
		}
	}
}
void buildHeap(int *a,int n)
{
	int i;

	for(i=n/2; i>=1;i--)
	{
		retro(a,n,i);
	}
}
