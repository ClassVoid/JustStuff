#ifndef HEADER3_H_
#define HEADER3_H_

struct ELEM{
    char c;
    ELEM *leg;
};

struct Stack{
	int data;
	Stack *leg;
};
//stiva de caractere
void init(ELEM *&cap);
bool IsEmpty(ELEM *cap);
void push(ELEM *&cap,char val);
bool pop(ELEM *&cap,char &val);
bool top(ELEM *cap,char &val);
//stiva de intregi
void initi(Stack *&s);
void pushi(Stack *&s,int val);
bool popi(Stack *&s,int &val);
//tansformari
char *conversie(char *s);
int evaluare(char *s);

#endif
