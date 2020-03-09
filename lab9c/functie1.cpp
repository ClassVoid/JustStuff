#include <iostream>
#include <cstring>
#include "header1.h"
using namespace std;

Nod *MakeNode(int val)
{
	Nod *p;
	p = new Nod;
	p->data = val;
	p->stg = 0;
	p->drt = 0;
	return p;
}
void Insert(Nod *&r, int val)
{
	if (r == 0)
	{
		r = MakeNode(val);
	}
	else
	{
		if (val < r->data)
		{
			Insert(r->stg, val);
		}
		else
		{
			if (val > r->data)
			{
				Insert(r->drt, val);
			}
		}
	}
}
Nod *BuildTree()
{
	char s[128];
	int flag = 0, dim, i = 0,nr=0;
	Nod *r=0;
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

void Inorder(Nod *r)
{
	if (r != 0)
	{
		Inorder(r->stg);
		cout << r->data << " ";
		Inorder(r->drt);
	}
	
}

bool Search(Nod *r, int val)
{
	if (r == 0)
		return 0;
	else
	{
		if (val < r->data)
			return Search(r->stg, val);
		else
		{
			if (val > r->data)
				return Search(r->drt, val);
			else
				return 1;
		}
	}
}

void DeleteNode(Nod *&r, int val) 
{
	if (r == 0)
	{
		cout << "eroare: valoarea " << val << " nu este in arbore!";
	}
	else
	{
		if (val < r->data)
			DeleteNode(r->stg, val);
		else
		{
			if (val > r->data)
				DeleteNode(r->drt, val);
			else
				DeleteRoot(r);
		}
	}
}
void DeleteRoot(Nod *&r)
{
	Nod *p = r;
	if (r->stg == 0)
		r = r->drt;
	else
	{
		if (r->drt == 0)
			r = r->stg;
		else
		{
			r = RemoveGreatest(r->stg);
			r->stg = p->stg;
			r->drt = p->drt;
		}
	}
	delete p;
}
Nod *RemoveGreatest(Nod *&r)
{
	Nod *p;
	if (r->drt == 0)
	{
		p = r;
		r = r->stg;
		return p;
	}
	else
		return RemoveGreatest(r->drt);
}

void PrintInd(Nod *r, int level)
{
	int i;
	for (i = 0; i < level; i++)
	{	
		cout << " ";
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

void Eliberare(Nod *&r)
{
	if (r->stg== 0 && r->drt==0)
	{
		delete r;
		r = 0;
	}
	else
	{
		if(r->stg!=0)
		{
			Eliberare(r->stg);
		}
		if(r->drt!=0)
		{
			Eliberare(r->drt);
		}
	}
}
