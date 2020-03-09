#ifndef HEADER5_H_
#define HEADER5_H_

struct List{
	int data;
	List *leg;
};

struct Queue{
	List *head,*tail;
};
//variabila de tip Queue nu va fi retinuta in pointer
//coada e dinamica btw

bool isEmpty(Queue &q);
void init(Queue &q);
void put(Queue &q,int val);
int get(Queue &q);
int front(Queue &q);

#endif
