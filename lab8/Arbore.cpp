//#pragma warning(disable:4996)
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Arbore.h"
using namespace std;

static char car = 0;

static void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	getchar();
	exit(1);
}

static char readchar()
{
	char c;
	do  c = getchar();  while (c == ' ');
	return c;
}

static char citesteNume()
{
	char c;//de la 0 la 9
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}

static Nod* citesteArbore()
{
	Nod* rad;
	if (car == '-')//e nod null
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Nod;//aloc mem pt nod
		rad->data = citesteNume();//citesc numele car
		if (car != '(')//daca e frunza
		{
			rad->stg = 0;
			rad->drt = 0;
		}
		else//daca nu e frunza
		{
			car = readchar();//stabilesc ce e nodul din stanga
			rad->stg = citesteArbore();//pornesc catre stanga
			if (car != ',')//dreapta e nod nul
			{
				rad->drt = 0;
			}
			else
			{
				car = readchar();//stabilesc ce e dreapta
				rad->drt = citesteArbore();//merg pe drpt
			}
			if (car != ')')  eroare();
			car = readchar();//stabilesc ce va fi urmatorul nod
		}
	}
	return rad;
}

Nod* creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();//char stabileste ce e primul nod
	return citesteArbore();
}
//
void init(Queue *&q)
{
	q=new Queue;
	q->head=0;
	q->tail=0;
}
void Put(Queue *&q, Nod *r)
{	
	Elem *p;
	p=new Elem;
	p->data=r;
	
	if(q->head==0)
	{
		q->tail=p;
		q->head=p;
	}
	else
	{
		p->leg=q->tail;
		q->tail=p;
	}
}
bool IsEmpty(Queue *q)
{
	if(q->head==0)
	return 1;
	else
	return 0;
}
bool Get(Queue *&q,Nod *&a)
{
	Elem *p;
	Elem *aux=q->tail;
	if(!IsEmpty(q))
	{
		p=q->head;
		a=p->data;
		while(aux->leg!=q->head)
		{
			aux=aux->leg;
		}
		q->head=aux;
		delete p;
		return 1;
	}
	else
	{
		return 0;
	}
}

//
void inord(Nod *p)
{
	if(p!=0)
	{	
		inord(p->stg);
		cout<<p->data<<" ";
		inord(p->drt);
	}
}
void postord(Nod *p)
{
	if(p!=0)
	{
		postord(p->stg);
		postord(p->drt);
		cout<<p->data<<" ";
	}
}

void AfisLinie(Nod *r)
{	
	//asta e gresita
	Queue *q;
	Nod *p;
	init(q);
	Put(q,r);
	while(!IsEmpty(q))
	{
		Get(q,p);
		cout<<p->data<<" ";
		if(p->stg!=0)
		Put(q,p->stg);
		if(p->drt!=0)
		Put(q,p->drt);
	}
}
