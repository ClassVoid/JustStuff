#include <iostream>
#include "header1.h"
using namespace std;

bool Eq=false;

AVL* makeNod(int val)
{
	AVL *p=0;

	p=new AVL;
	p->data=val;
	p->bf=0;
	p->stg=0;
	p->drt=0;

	return p;
}
void insert(AVL *&r,int val)//merge doar recursiv
{

	if(r==0)
	{
		r=makeNod(val);
	}
	else
	{
		if(r->data > val)
		{
			insert(r->stg,val);
			echilibrare(r, val,true);
		}
		else
		{
			insert(r->drt,val);
			echilibrare(r, val, false);
		}
	}
}
AVL* search(AVL *r,int val)//caut in main inainte sa inserez
{
	if(r == 0)
	{
		return 0;
	}
	else
	{
		if(r->data > val)
		{
			return search(r->stg,val);
		}
		else
		{
			if(r->data < val)
			{
				return search(r->drt,val);
			}
			else
			{
				return r;
			}
		}
	}
}
AVL* removeGreatest(AVL *&r)
{
	AVL *p=r,*q=0;

	while(p->drt!=0)
	{
		q=p;
		p=p->drt;
	}
	if(q!=0)
	{
		q->drt=p->stg;
	}
	return p;
}
void deletRoot(AVL *&r)
{
	AVL *p=r;

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
void afisare(AVL *r)
{
	if(r!=0)
	{
		afisare(r->stg);
		cout<<r->data<<" ";
		afisare(r->drt);
	}
}
void deletAll(AVL *&r)
{
	if(r!=0)
	{
		deletAll(r->stg);
		deletAll(r->drt);
		delete r;
	}
}
//lab
void RSS(AVL *&a)
{
	AVL *b;
	b=a->drt;
	a->drt=b->stg;
	b->stg=a;
	a->bf=b->bf=0;
}
void RDS(AVL *&a)
{
	AVL *b,*c;

	b=a->drt;
	c=b->stg;

	switch(c->bf)
	{
		case 0:
			a->bf=b->bf=0;
		break;
		case -1:
			a->bf=0;
			b->bf=-1;
		break;
		case 1:
			a->bf=-1;
			b->bf=0;
		break;
	}

	a->drt=c->stg;
	b->stg=c->drt;
	c->bf=0;
	c->drt=b;
	c->stg=a;
	a=c;
}
void RSD(AVL *&a)
{
	AVL *b;

	b=a->stg;
	a->stg=b->drt;
	b->drt=a;
	a->bf=b->bf=0;
}
void RDD(AVL *&a)
{
	AVL *b,*c;
	b=a->stg;
	c=b->drt;

	switch(c->bf)
	{
		case 0:
			a->bf=b->bf=0;
		break;
		case -1:
			a->bf=0;
			b->bf=1;
		break;
		case 1:
			a->bf=-1;
			b->bf=0;
		break;
	}

	a->stg=c->drt;
	b->drt=c->stg;
	c->bf=0;
	c->drt=a;
	c->stg=b;
	a=c;
}
void echilibrare(AVL *&a,int x,bool stg)
{
	if (Eq)
	{
		if(stg)
		{
			switch(a->bf)
			{
				case 1:
					Eq=false;
					if(x < a->stg->data)
					{
						RSD(a);
					}
					else
					{
						RDD(a);
					}
				break;
				case 0:
					a->bf=1;
				break;
				case -1:
					a->bf=0;
					Eq=false;
				break;
			}
		}
		else
		{
			switch(a->bf)
			{
				case 1:
					a->bf=0;
					Eq=false;
				break;
				case 0:
					a->bf=-1;
				break;
				case -1:
					Eq=false;
					if(x < a->drt->data)
					{
						RDS(a);
					}
					else
					{
						RSS(a);
					}
				break;
			}
		}
	}
	else
	{
		Eq=false;
	}
}
