#ifndef HEADER10_H_
#define HEADER10_H_

struct AVL{
	int data;
	int bf;
	AVL *stg,*drt;
};

AVL* makeNod(int val);
void insert(AVL *&r,int val);
AVL* search(AVL *r,int val);
AVL* removeGreatest(AVL *&r);
void deletRoot(AVL *&r);
void afisare(AVL *r);
void deletAll(AVL *&r);

//lab
void RSS(AVL *&a);
void RDS(AVL *&a);
void RSD(AVL *&a);
void RDD(AVL *&a);
void echilibrare(AVL *&a,int x,bool stg);

#endif
