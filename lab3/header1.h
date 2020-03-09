#ifndef HEADER3_H_
#define HEADER3_H_

struct List{
	int data;
	List *leg;
};

void init(List *&p);
void insert(List *&p,int val);//inserez in fata
bool inpos(List *&p,int val,int pos);
void delet(List *&p);
bool delpos(List *&p,int pos);
void afisare(List *p);
bool search(List *p,int val);

void frontBack(List *p);
bool loopCheck(List *p);
int manInTheMiddle(List *p);
void ReDo(List *&p);

#endif
