#include <iostream>
#include <cstring>
#include "header1.h"
using namespace std;

bool eq_req;//in make nod dai lui eq_req=true

void RSS(AVL *&a){
	AVL *b;
	b=a->drt;
	a->drt=b->stg;
	b->stg=a;
	a->bf=b->bf=0;
	a=b;
}
void RSD(AVL *&a){
	AVL *b;
	b=a->stg;
	a->stg=b->drt;
	b->drt=a;
	a->bf=b->bf=0;
	a=b;
}
void RDS(AVL *&a){
	AVL *b,*c;
	b=a->drt;
	c=b->stg;
	//actualizez bf pt starea finala
	switch(c->bf)
	{
		case 0:
			a->bf=b->bf=0;
		break;
		case -1:
			a->bf=1;
			b->bf=0;
		break;
		case 1:
			a->bf=0;
			b->bf=-1;
		break;
	}
	a->drt=c->stg;
	b->stg=c->drt;
	c->bf=0;
	c->stg=a;
	c->drt=b;
	a=c;
}
void RDD(AVL *&a){
	AVL *b,*c;
	b=a->stg;
	c=b->drt;
	//actualizez bf pt starea finala
	switch(c->bf)
	{
		case 0:
			a->bf=b->bf=0;
		break;
		case -1:
			a->bf=0;
			b->bf=1;
		break;
		case 1:
			a->bf=-1;
			b->bf=0;
	}
	a->stg=c->drt;
	b->drt=c->stg;
	c->bf=0;
	c->drt=a;
	c->stg=b;
	a=c;
}
void Echilibrare(AVL *&a,int x,bool  stg){
	if(eq_req)
		if(stg==true)
		{
		switch(a->bf)
		{
			case 1:
				eq_req=false;
				(x < a->stg->data)?RSD(a):RDD(a);
			break;
			case 0:
				a->bf=1;
			break;
			case -1:
				a->bf=0;
				eq_req=false;
			break;
		}
		}
		else
		{
		switch(a->bf)
		{
			case 1:
				a->bf=0;
				eq_req=false;
			break;
			case 0:
				a->bf=-1;
			break;
			case -1:
				eq_req=false;
				(x>a->drt->data)?RSS(a):RDS(a);
			break;
		}
		}
	else
	eq_req=false;
}

AVL *MakeNode(int val)
{
	AVL *p;
	p = new AVL;
	p->data = val;
	p->stg = 0;
	p->drt = 0;
	p->bf=0;
	eq_req=true;
	return p;
}
void Insert(AVL *&r, int val)
{
	if (r == 0)
	{
		cout<<"\nam inserat "<<val<<endl;
		r = MakeNode(val);
	}
	else
	{
		if (val < r->data)
		{
			Insert(r->stg, val);
			Echilibrare(r,val,true);
		}
		else
		{
			if (val > r->data)
			{
				Insert(r->drt, val);
				Echilibrare(r,val,false);
			}
		}
	}
}
AVL *BuildTree()
{
	char s[128];
	int flag = 0, dim, i = 0,nr=0;
	AVL *r=0;
	cout << "introduceti numerele\n";
	cin.getline(s, 128);
	dim = (int)strlen(s);
	while (flag == 0 && i < dim)
	{
		if (i > 0 && s[i] == ' ' && s[i - 1] != ' ')
		{
			Insert(r, nr);
			nr = 0;
		}
		else
		{
			if (i > 0 && s[i] == '0' && s[i - 1] == ' ')
			{
				flag = 1;
			}
			else
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					nr = nr * 10 + (s[i] - '0');
				}
			}
		}
		i++;
	}
	return r;
}

void Inorder(AVL *r)
{
	if(r != 0)
	{
		Inorder(r->stg);
		cout << r->data << " ";
		Inorder(r->drt);
	}
}

void PrintInd(AVL *r, int level)
{
	int i;
	for (i = 0; i < level; i++)
	{	
	cout << "\t";
	}

	if (r == 0)
	{
		cout << "-" << endl;
	}
	else
	{
		cout << r->data << endl;
		PrintInd(r->stg, level + 1);
		PrintInd(r->drt, level + 1);
	}
	
}

void Sterg(AVL *r)
{
	if(r!=0)
	{
		Sterg(r->stg);
		Sterg(r->drt);
		delete r;
	}
}

