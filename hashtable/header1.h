#ifndef HEADER6_H_
#define HEADER6_H_

struct Nod{
	char *s;
	Nod *leg;
};

int functie(char *s,int n);
Nod** init(int n);//n e numarul de elemente
bool search(Nod **ht,char *s,int n);
void insert(Nod **ht,char *s,int n);
void listare(Nod **ht,int n);

#endif
