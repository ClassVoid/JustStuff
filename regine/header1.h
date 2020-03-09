#ifndef HEADER1_H_
#define HEADER1_H_

int **zeros(int n);
void initiere(int *&a);
bool solutie(int *&a,int n,int &c);
bool verific(int **a,int n,int l,int c);//nu pot verifica pt prima linie
bool coloana(int **a,int l,int c);//verific coloana
bool diag(int **a,int l,int c,int n);
void afisare(int **a,int n);
bool bkt(int n);//functie de asamblare
#endif
