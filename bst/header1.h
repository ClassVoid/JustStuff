#ifndef HEADER9_H_
#define HEADER9_H_

struct Nod{
	int data;
	Nod *stg,*drt;
};

Nod* makeNod(int val);
void insert(Nod *&r,int val);
Nod* search(Nod *r,int val);
Nod* removeGreatest(Nod *&r);
void deletRoot(Nod *&r);
void delet(Nod *&r,int a);
void afisare(Nod *r);
void deletAll(Nod *&r);
#endif
