#include <iostream>
#include "header1.h"
using namespace std;


bool isEmpty(Queue &q)
{
	if(q.head == 0 || q.tail == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void init(Queue &q)
{
	q.head=0;
	q.tail=0;
}
void put(Queue &q,int val)
{
	List *p;

	p=new List;
	p->data=val;
	p->leg=0;
	if(!isEmpty(q))
	{
		q.tail->leg=p;
		q.tail=p;
	}
	else
	{
		q.head=p;
		q.tail=p;
	}
}
int get(Queue &q)
{
	int val;
	List *p;
	
	val=q.head->data;
	p=q.head;
	q.head=q.head->leg;
	delete p;
	return val;
}
int front(Queue &q)
{
	return q.head->data;
}
