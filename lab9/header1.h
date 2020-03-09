#ifndef HEADER1_H_
#define HEADER1_H_

struct Nod{
	int data;
	Nod *stg,*drt;
};

Nod * MakeNod(int a);
void insert(Nod *&r,int a);
void inordine(Nod *r);
Nod *search(Nod *r, int a);
void afiskey(Nod *r);
void afisindent(Nod *r);
void deletenod(Nod *&rad,int a);

#endif
