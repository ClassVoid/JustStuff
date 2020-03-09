#include <iostream>
#include "header1.h"
using namespace std;

int **zeros(int n)
{
	int **mat=0,i,j;

	mat=new int*[n];

	for(i=0;i<n;i++)
	{
		mat[i]=new int[n];
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			mat[i][j]=0;
		}
	}
	
	return mat;
}
void afisare(int **mat,int n)
{
	int i,j;

	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

void delet(int **mat,int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		delete mat[i];
	}
	delete mat;
}

//lista
void insert(List *&p,int val)
{
	List *q=0;

	q=new List;
	q->data=val;
	q->leg=p;
	p=q;
}
void afisare(List *p)
{
	List *q=p;

	while(q!=0)
	{
		cout<<q->data<<" ";
		q=q->leg;
	}
	cout<<endl;
}
void sterg(List *&p)
{
	List *q=p;
	
	while(p!=0)
	{
		p=p->leg;
		delete q;
		q=p;
	}
}

//Stiva
void push(List *&s,int val)
{
	List *q=0;

	q=new List;
	q->data=val;
	q->leg=s;
	s=q;
}
int pop(List *&s)
{
	List *q;
	int val;
	
	if(s!=0)
	{
		q=s;
		val=q->data;
		s=s->leg;
		delete q;
		return val;
	}
	return -1;
}

//Queue
void init(Queue &q)
{
	q.head=0;
	q.tail=0;
}
void put(Queue &q,int val)
{
	List *p=0;

	if(!isEmpty(q))
	{
		p=new List;
		p->data=val;
		q.tail->leg=p;
		q.tail=p;
	}
	else
	{
		p=new List;
		p->data=val;
		p->leg=0;
		q.tail=p;
		q.head=p;
	}
}
int get(Queue &q)
{
	List *p=q.head;
	int val;
	
	val=q.head->data;
	q.head=q.head->leg;
	delete p;

	return val;
}
bool isEmpty(Queue q)
{
	if(q.head==0 || q.tail==0)
	{
		return 1;
	}
	return 0;
}
