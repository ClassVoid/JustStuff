#include <iostream>
#include "header1.h"
using namespace std;

void init(List *&p)
{
	p=0;
}
void insert(List *&p,int val)
{
	List *q;

	q=new List;
	q->data=val;
	q->urm=p;
	if(p!=0)
	{
		p->pre=q;
	}
	q->pre=0;
	p=q;
}
bool inpos(List *&p,int val,int pos)
{
	int i=0;
	List *q=p,*qq;


	if(pos==1)
	{
		insert(p,val);
		return 1;
	}
	else
	{
		do
		{
			qq=q;
			q=q->urm;
			i++;
		}while(i<pos && q!=0);

		if(q!=0 && pos>1)
		{
			insert(q,val);
			q->pre=qq;
			qq->urm=q;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
void delet(List *&p)//sterg din fata
{
	List *q=p;

	p=p->urm;
	delete q;
	if(p!=0)
	{
		p->pre=0;
	}
}
bool delpos(List *&p,int pos)
{
	int i=1;
	List *q=p,*qq;
	
	if(pos==1)
	{
		delet(p);
		return 1;
	}
	else
	{
		do
		{
			qq=q;
			q=q->urm;
			i++;
		}while(i<pos && q!=0);

		if(q!=0)
		{
			delet(q);
			qq->urm=q;
			if(q!=0)
			{
				q->pre=qq;			
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
void afisare(List *p)
{
	
	while(p->urm!=0)
	{
		cout<<p->data<<" ,";
		p=p->urm;
	}
	cout<<p->data<<endl;
}
void ReDo(List *&p)
{

}
