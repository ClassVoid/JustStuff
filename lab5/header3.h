#ifndef HEADER3_H_
#define HEADER3_H_

struct ELEM{
    char c;
    ELEM *leg;
};

void init(ELEM *&cap);
bool IsEmpty(ELEM *cap);
void push(ELEM *&cap,char val);
bool pop(ELEM *&cap,char &val);
bool top(ELEM *cap,char &val);
char *conversie(char *s);
int evaluare(char *s);

#endif
