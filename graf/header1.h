#ifndef HEADER13_H_
#define HEADER13_H_

struct List{
	int data;
	List *leg;
};

struct Queue{
	List *head,*tail;
};

//Queue
void init(Queue &q);
void put(Queue &q,int val);
int get(Queue &q);
bool isEmpty(Queue q);

//lista
void insert(List *&p,int val);
void afisare(List *p);
void sterg(List *&p);

//Stiva
void push(List *&s,int val);
int pop(List *&s);

//matrice
int **zeros(int n);
void afisare(int **mat,int n);
void delet(int **mat,int n);

#endif
