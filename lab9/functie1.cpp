#include <iostream>
#include "header1.h"
using namespace std;


Nod * MakeNod(int a)
{
	Nod *p;
	p=new Nod;
	p->data=a;
	p->stg=0;
	p->drt=0;
	return p;
}
void insert(Nod *&r,int a)
{
	if(r==0)
	{
		r=MakeNod(a);
	}
	else
	{
		if(a < r->data)
		{
			insert(r->stg,a);
		}
		else
		{
			if(a > r->data)
			{
				insert(r->drt,a);
			}
		}
	}
}
void inordine(Nod *r)
{
	if(r)
	{
		inordine(r->stg);
		cout<<r->data<<" ";
		inordine(r->drt);
	}
}
Nod *search(Nod *r, int a)
{
	if(r==0)
	{
		return 0;
	}
	else
	{
		if(a < r->data)
		{
			return search(r->stg,a);
		}
		else
		{
			if(a > r->data)
			{
				return search(r->drt,a);
			}
			else
			return r;
		}
	}
}
void afiskey(Nod *r)
{
	
}
void afisindent(Nod *r)
{

}
void deletenod(Nod *&rad,int a)
{

}

