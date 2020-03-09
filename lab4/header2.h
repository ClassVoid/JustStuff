#ifndef HEADER42_H_
#define HEADER42_H_

struct List{
	int data;
	List *leg;
};

void init(List *&p);
void insert(List *&p,int val);
bool inpos(List *&p,int val,int pos);
void delet(List *&p);
void afisare(List *p);
bool delpos(List *&p,int pos);
void ReDo(List *&p);

#endif
