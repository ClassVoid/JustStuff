#pragma once

struct Nod {
	char data;
	Nod* stg, *drt;
};

struct Elem{
	Nod *data;
	Elem *leg;
};

struct Queue{
	Elem *head,*tail;
};

static void eroare();
static char readchar();
static char citesteNume();
static Nod* citesteArbore();
Nod* creareArbore();

//
void init(Queue *&q);
void Put(Queue *&q, Nod *r);
bool IsEmpty(Queue *q);
bool Get(Queue *&q,Nod *&a);
//
void inord(Nod *p);
void postord(Nod *p);
void AfisLinie(Nod *r);

