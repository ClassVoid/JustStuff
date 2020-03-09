#ifndef HEADER41_H_
#define HEADER41_H_

struct List{
	int data;
	List *urm,*pre;
};

void init(List *&p);
void insert(List *&p,int val);
bool inpos(List *&p,int val,int pos);
void delet(List *&p);
bool delpos(List *&p,int pos);
void afisare(List *p);
void ReDo(List *&p);

#endif
