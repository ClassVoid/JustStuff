#include <iostream>
#include "header1.h"
using namespace std;

int **zeros(int n)
{	
	int i,j,**a;

	a=new int*[n];
	for(i=0;i<n;i++)
	{
		a[i]=new int[n];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	return a;
}

void initiere(int *&a)
{
	a[0]=1;
}

bool solutie(int *&a,int n,int &c)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(i>0 && a[i-1]==1)
		{
			a[i-1]=0;
			a[i]=1;
			c=i;
			return 1;
		}
	}
	return 0;
}

bool coloana(int **a,int l,int c)//0=rau
{
	int i;

	for(i=l-1;i>=0;--i)
	{
		if(a[i][c]==1)
		return 0;
	}
	return 1;
}

bool diag(int **a,int l,int c,int n)//0 e rau
{
	int i,j;

	//verific la stanga
	i=l-1;
	j=c-1;
	while(i>=0 && j>=0)
	{
		if(a[i][j]==1)
		return 0;
		i--;
		j--;
	}
	//verific la dreapta
	i=l-1;
	j=c+1;
	while(i>=0 && j<n)
	{
		if(a[i][j]==1)
		return 0;
		i--;
		j++;
	}
	return 1;
}

bool verific(int **a,int n,int l,int c)
{

	if(coloana(a,l,c) && diag(a,l,c,n)) 
	{
		return 1;
	}	
	return 0;
}
void afisare(int **a,int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool bkt(int n)
{	
	//initieri
	int l,c,p,**a,v,stop,i,nr;
	
	a=zeros(n);
	l=0;
	c=0;
	p=1;
	v=1;
	nr=0;
	
	stop=0;
	cout<<"intru in while"<<endl;

	while(stop==0)
	{
		if(p==1)
		{
			initiere(a[l]);
			p=0;
			//cout<<"am initializat linia "<<l<<endl;
			if(l!=0)
			{
				v=verific(a,n,l,c);
			//	cout<<"verificare linia"<<l<<endl;
			}
		}
		else
		{
			if(solutie(a[l],n,c))
			{
				v=verific(a,n,l,c);
			//	cout<<"solutie si verificare linia "<<l<<" "<<c;
			//	cout<<" "<<coloana(a,l,c)<<" "<<diag(a,l,c,n)<<endl;
			//	afisare(a,n);
			}
			else
			{
				if(l==0)
				{
					stop=1;
				}
				else
				{	
					a[l][c]=0;
					l--;
					for(i=0;i<n;i++)
					{
						if(a[l][i]==1)
						c=i;
					}
				}
			}
		}
		if(v!=0)
		{
			l++;
			if(l==n)
			{
				afisare(a,n);
				cout<<endl;
				l--;
				v=0;
				nr++;
			}
			else
			{
				p=1;
				c=0;
			}
		}
	}
	
	cout<<"nr solutii = "<<nr<<endl;
	//eliberez mem
	for(i=0;i<n;i++)
	{
		delete a[i];
	}
	delete a;
	if(stop==1)
	return 0;
	else
	return 1;
}
