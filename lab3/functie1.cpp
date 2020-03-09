#include <iostream>
#include "header1.h"
using namespace std;

void init(List *&p)
{
	p=0;
}
void insert(List *&p,int val)//inserez in fata
{
	List *q=0;
	q=new List;

	q->data=val;
	q->leg=p;
	p=q;
}
bool inpos(List *&p,int val,int pos)
{
	int i=1;
	List *q=p,*qq;

	while(i<pos && q!=0)
	{	
		qq=q;
		q=q->leg;
		i++;
	}
	if(q!=0 && pos>1)
	{
		insert(q,val);
		qq->leg=q;
		return 1;
	}
	else
	{
		if(pos==1)
		{
			insert(p,val);
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

	p=p->leg;
	delete q;
}
bool delpos(List *&p,int pos)
{
	int i=1;
	List *q=p,*qq;

	while(q!=0 && i<pos)
	{
		qq=q;
		q=q->leg;
		i++;
	}
	if(q!=0 && pos>1)
	{
		delet(q);
		qq->leg=q;
		return 1;
	}
	else
	{
		if(pos==1)
		{
			delet(p);
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
	while(p!=0 && p->leg!=0)
	{
		cout<<p->data<<" ,";
		p=p->leg;
	}
	cout<<p->data<<endl;
}
bool search(List *p,int val)
{
	while(p!=0 && p->leg!=0)
	{
		if(p->data==val)
		{
			return 1;
		}
	}
	return 0;
}

void frontBack(List *p)
{
	if(p!=0)
	{
		cout<<p->data<<" ,";
		frontBack(p->leg);
		cout<<p->data<<" ;";
	}
}
bool loopCheck(List *p)
{	
	List *q=p,*qq=p;

	do
	{
		q=q->leg;
		qq=qq->leg;
		if(qq!=0)
		{
			qq=qq->leg;
		}

	}while(qq!=0 && q!=qq);
	
	if(qq==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int manInTheMiddle(List *p)
{
	List *q=p,*qq=p;
	if(q->leg!=0)
	{
		do
		{
			q=q->leg;
			qq=qq->leg;
			if(qq!=0)
			{
				qq=qq->leg;
			}
		}while(qq!=0 && qq->leg!=0);
	}
	return q->data;
}
void ReDo(List *&p)
{
	List *q=p,*qq,*pre=p;
	
	if(q->leg!=0)
	{	
		qq=q->leg;
		q->leg=0;
		q=qq;
		while(q->leg!=0)
		{
			qq=q->leg;
			q->leg=pre;
			pre=q;
			q=qq;
		}
		q->leg=pre;
	}
	p=q;
}
