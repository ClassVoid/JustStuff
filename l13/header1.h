#ifndef HEADER1_H_
#define HEADER1_H_

struct List{
	int data;
	List *leg;
};

struct Stack{
	int data;
	Stack *leg;
};

struct Queue{
	List *head,*tail;
};

//lista
bool isemptyL(List *p);
void insert(List *p,int k);
void stergl(List *p);

//stiva
void create();
bool isemptyS(Stack *s);
void push(Stack *s,int k);
void pop(Stack *s,int &k);

//Queue
void initQueue(Queue &q);
bool isemptyQ(Queue q);
void put(Queue &q,int k);
void get(Queue &q,int &q);


#endif
