#ifndef HEADER1_H_
#define HEADER1_H_

struct AVL{
	int data;
	int bf;
	AVL *stg,*drt;
};

void RSS(AVL *&a);
void RSD(AVL *&a);
void RDS(AVL *&a);
void RDD(AVL *&a);
void Echilibrare(AVL *&a,int x,bool  stg);
//din lab 9

AVL *MakeNode(int val);
void Insert(AVL *&r, int val);
AVL *BuildTree();//citeste sirul si creeaza arborele
void PrintInd(AVL *r, int level);
void Inorder(AVL *r);
void Sterg(AVL *r);

#endif
