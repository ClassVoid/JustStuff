#include <iostream>
#include "header2.h"
using namespace std;

void init(List *&p)
{
	p=0;
}
void insert(List *&p,int val)

{
	List *q,*qq=p;

	q=new List;
	q->data=val;

	if(p==0)
	{
		q->leg=q;	
	}
	else
	{
		while(qq->leg!=p)
		{
			qq=qq->leg;
		}
		qq->leg=q;
		q->leg=p;
	}
	p=q;
}
bool inpos(List *&p,int val,int pos)
{
	int i=1;
	List  *q=p;

	if(pos==1)
	{
		insert(p,val);
		return 1;
	}
	else
	{
		do
		{
			q=q->leg;
			i++;
		}while(i<pos && q!=p);

		if(q!=p && pos>1)
		{
			insert(q,val);
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
void delet(List *&p)
{
	List *q=p,*qq=p;

	while(qq->leg!=p)
	{
		qq=qq->leg;
	}
	p=p->leg;
	delete q;
	qq->leg=p;
}
bool delpos(List *&p,int pos)
{
	int i=1;
	List *q=p;
	
	if(pos==1)
	{
		delet(p);
		return 1;
	}
	else
	{
		do
		{
			q=q->leg;
			i++;
		}while(i<pos && q!=p);
	
		if(q!=p && pos>1)
		{
			delet(q);
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
	List *q=p;
	
	do
	{
		cout<<q->data<<" ,";
		q=q->leg;
	}while(q->leg!=p);
	cout<<q->data<<endl;
}
void ReDo(List *&p)
{

}


