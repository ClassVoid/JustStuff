#include <iostream>
#include "header1.h"
using namespace std;

Nod* makeNod(int val)
{
	Nod *p=0;

	p=new Nod;
	p->data=val;
	p->stg=0;
	p->drt=0;
	return p;
}
void insert(Nod *&r,int val)
{
	Nod *p;
	int ok;

	if(r==0)//e primul nod
	{
		r=makeNod(val);
	}
	else
	{	
		if(search(r,val)==0)
		{
			p=r;
			ok=1;
			while(ok)
			{
				if(p->data>val)
				{
					if(p->stg==0)
					{
						p->stg=makeNod(val);
						ok=0;
					}
					else
					{
						p=p->stg;
					}
				}
				else
				{
					if(p->drt==0)
					{
						p->drt=makeNod(val);
						ok=0;
					}
					else
					{
						p=p->drt;
					}
				}
			}
		}
	}
}
Nod* search(Nod *r,int val)
{
	Nod *p=r;

	while(p!=0 && p->data!=val)
	{
		if(val < p->data)
		{
			p=p->stg;
		}
		else
		{
			p=p->drt;
		}
	}
	if(p==0)
	{
		return 0;
	}
	else
	{
		return p;
	}
}
Nod* removeGreatest(Nod *&r)//intorc cel mai mare nod si tai accesul
{
	Nod *p=r,*q=0;

	while(p->drt!=0)
	{	
		q=p;
		p=p->drt;
	}
	if(q!=0)
	{
		//tai accesul
		q->drt=p->stg;
	}
	return p;
}
void deletRoot(Nod *&r)
{
	Nod *p=r;

	if(p->stg==0)
	{
		r=r->drt;
	}
	else
	{
		if(p->drt==0)
		{
			r=r->stg;
		}
		else
		{
			r=removeGreatest(r->stg);
			r->stg=p->stg;
			r->drt=p->drt;
		}
	}
	delete p;
}
void delet(Nod *&r,int val)
{
	Nod *p=r;

	while(p!=0 && p->data!=val)
	{
			if(p->data > val)
		{
			p=p->stg;
		}
		else
		{
			p=p->drt;
		}
	}
	if(p!=0)
	{
		deletRoot(p);
	}
	else
	{
		cout<<"valoarea nu se afla in arbore\n";
	}
}

void afisare(Nod *r)
{
	if(r!=0)
	{
		afisare(r->stg);
		cout<<r->data<<" ";
		afisare(r->drt);
	}
}

void deletAll(Nod *&r)
{	
	if(r!=0)
	{
		deletAll(r->stg);
		deletAll(r->drt);
		deletRoot(r);	
	}
}
