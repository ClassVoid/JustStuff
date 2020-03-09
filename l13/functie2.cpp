#include <iostream>
#include "header1.h"
using namespace std;


//lista
bool isemptyL(List *p)
{
	if(p==0)
	return 1;
	else
	return 0;
}
void insert(List *&p,int k)
{
	List *q,*r=p;
	q=new List;
	q->data=k;
	
	while(r->leg!=0)
	{
		r=r->leg;
	}
	r->leg=q;
	q->leg=0;
}
void stergl(List *&p)
{
	List *r;
	while(p->leg!=0)
	{
		r=p->leg;
		delete p;
		p=r;
	}
}

//stiva
Stack *create()
{
	Stack *s;
	s=new Stack;
	s->leg=0;
}
bool isemptyS(Stack *s)
{
	if(s==0)
	return 1;
	else
	return 0;
}
void push(Stack *&s,int k)
{
	Stack p;

	if(!isemptyS(s))
	{
		p=new Stack;
		p->leg=s;
		s=p;
	}
	else
	{
		p=create();
		s=p;
	}
	s->data=k;
}
bool pop(Stack *s,int &k)
{
	Stack *p;

	if(!isemptyS(s))
	{
		k=s->data;
		p=s;
		s=s->leg;
		delete p;
	}
	else
	return 0;
}

//Queue
void initQueue(Queue &q)
{
	q.head=0;
	q.tail=0;
}
bool isemptyQ(Queue &q)
{
	if(tail==0)
	return 1;
	else
	return 0;
}
void put(Queue &q,int k)
{
	Queue *p;

}
void get(Queue &q,int &q)
{

}

