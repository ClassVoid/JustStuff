#pragma once
struct Nod {
	int data;
	Nod *stg, *drt;
};

Nod *MakeNode(int val);
void Insert(Nod *&r, int val);
Nod *BuildTree();//citeste sirul si creeaza arborele
void Inorder(Nod *r);
bool Search(Nod *r, int val);
void DeleteNode(Nod *&r, int val);
void DeleteRoot(Nod *&r);
Nod *RemoveGreatest(Nod *&r);
void PrintInd(Nod *r, int level);
void Eliberare(Nod *&r);
