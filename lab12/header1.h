#ifndef HEADER12_H_
#define HEADER12_H_

#define M 6
enum tipNod{frunza, interior};

struct bnod{
	tipNod tip;
	int n;
	int val[M-1];
	bnod *leg[M];
};

void createBTree(bnod *&t);
bool IterativeSearch(bnod *r,int x);
bool RecursiveSearch(bnod *r,int x);
void display(bnod *v,int niv);
void Inorder(bnod *r);
void splitNode(bnod *&u,int i,bnod *&v);
void insertNonFullNode(bnod *&v,int k);
void insertBTree(bnod *&t,int k);
void DeleteNode(bnod *&r,int x);
int findPosition(bnod *p,int x);
void removeFromLeaf(bnod *&p,int idx);
void removeFromNonLeaf(bnod *&p,int idx);
void borrowFromPrevious(bnod *&p,int idx);
void borrowFromNext(bnod *&p,int idx);
void merge(bnod *&p,int idx);

#endif
