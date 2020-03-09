#include <iostream>
#include "header1.h"
using namespace std;

void createBTree(bnod *&t)
{
	t=new bnod;
	t->tip=frunza;
	t->n=0;
	for(int i=0;i < M-1;i++)
	{
		t->leg[i]=0;
	}
}
bool IterativeSearch(bnod *r,int x)
{
	bnod *p=r;
	int pos;

	while(p!=0)
	{
		pos=0;
		while(pos < p->n && p->val[pos] < x)
		{
			pos++;
		}
		if(pos < p->n && x==p->val[pos])
		{
			return 1;
		}
		p=p->leg[pos];
	}
	return 0;
}
bool RecursiveSearch(bnod *r,int x)
{
	int i=0;

	while(i < r->n && r->val[i] < x)
	{
		i++;
	}

	if(i < r->n && x == r->val[i])
	{
		return 1;
	}
	if(r->leg[i]==0)
	{
		return 0;
	}
	else
	{
		return RecursiveSearch(r->leg[i],x);
	}
}
void display(bnod *v,int niv)
{
	if(v)
	{
		if(v->tip == interior)
		{
			display(v->leg[0],niv+1);
		}
		for(int i=0; i < v->n;i++)
		{
			for(int j=0;j < niv;j++)
			{
				cout<<"\t";
			}
			cout<<v->val[i]<<endl;
			if(v->tip == interior)
			{
				display(v->leg[i+1],niv+1);
			}
		}
	}
}
void Inorder(bnod *r)
{
	if(r)
	{
		for(int i=0;i < r->n;i++)
		{
			Inorder(r->leg[i]);
			cout<<r->val[i];
		}
		Inorder(r->leg[r->n]);
	}
}
void splitNode(bnod *&u,int i,bnod *&v)
{
	bnod *w=new bnod;
	w->tip=v->tip;
	w->n=(M-1)/2;

	for(int k=1;k < M;k++)
	{
		w->leg[k]=0;
	}

	for(int j=0;j<=(M-1)/2;j++)
	{
		w->val[j]=v->val[j + (M-1)/2 + 1];
	}
	if(v->tip == interior)
	{
		for(int j=0;j <= (M-1)/2;j++)
		{
			w->leg[j]=v->leg[j+(M-1)/2+1];
		}
	}
	v->n=(M-1)/2;

	for(int j=u->n;j>=i+1;j--)
	{
		u->leg[j+1]=u->leg[j];
	}
	u->leg[i+1]=w;

	for(int j=u->n-1;j>=i;j--)
	{
		u->val[j+1]=u->val[j];
	}
	u->val[i]=v->val[(M-1)/2];
	u->n++;
}
void insertNonFullNode(bnod *&v,int k)
{
	int i=v->n;

	if(v->tip == frunza)
	{
		while(i>=1 && k<v->val[i])
		{
			v->val[i+1]=v->val[i];
			i--;
		}
		v->val[i]=k;
		v->n++;
	}
	else
	{	
		cout<<"\n1\n";
		while(i>=1 && k<v->val[i])
		{
			i--;
		}
		cout<<"2\n";
		if(k>v->val[i])
		{
			i++;
		}
		if(v->leg[i]!=0)
		if(v->leg[i]->n == M-1)
		{
			cout<<"4\n";
			splitNode(v,i,v->leg[i]);
			cout<<"5\n";
			if(k>v->val[i])
			{
				i++;
			}
		}
		insertNonFullNode(v->leg[i],k);
	}

}
void insertBTree(bnod *&t,int k)
{
	bnod *v=t,*u;

	if(v->n == M-1)
	{
		createBTree(u);
		//
		u->leg[0]=v;
		u->tip=interior;
		t=u;
		splitNode(u,0,v);
		cout<<"\nam iesit din split "<<k<<endl;
		insertNonFullNode(u,k);
		cout<<"\nam iesit din insert "<<k<<endl;
	}
	else
	{
		insertNonFullNode(v,k);
	}
}
void DeleteNode(bnod *&r,int x)
{
	int pos;
	pos=findPosition(r,x);

	if(pos<r->n && r->val[pos]==x)
	{
		if(r->tip==frunza)
		{
			removeFromLeaf(r,pos);
		}
		else
		{
			removeFromNonLeaf(r,pos);
		}
	}
	else
	{
		if(r->tip==frunza)
		{
			if(r->leg[pos]->n <= (M-1)/2)
			{
				if(pos!=1 && r->leg[pos]->n > (M-1)/2)
				{
					borrowFromPrevious(r,pos);
					DeleteNode(r->leg[pos],x);
				}
				else
				{
					if(pos!=r->n+1 && r->leg[pos]->n >(M-1)/2)
					{
						borrowFromNext(r,pos);
						DeleteNode(r->leg[pos],x);
					}
					else
					{
						if(pos!=r->n)
						{
							merge(r,pos);
							DeleteNode(r->leg[pos],x);
						}
						else
						{
							merge(r,pos-1);
							DeleteNode(r->leg[pos-1],x);
						}
					}
				}
			}
			else
			{
				DeleteNode(r->leg[pos],x);
			}
		}
	}
}
int findPosition(bnod *p,int x)
{
	int pos=0;

	while(pos < p->n && x > p->val[pos])
	{
		pos++;
	}
	return pos;
}
void removeFromLeaf(bnod *&p,int idx)
{
	for(int i=idx+1;i<p->n;i++)
	{
		p->val[i-1]=p->val[i];
	}
	p->n--;
}
void removeFromNonLeaf(bnod *&p,int idx)
{
	int k=p->val[idx];

	if(p->leg[idx]->n >(M-1)/2)
	{
		int pred;
		bnod *crt = p->leg[idx];

		while(crt->tip!=frunza)
		{
			crt=crt->leg[crt->n];
		}
		pred=crt->val[crt->n-1];
		p->val[idx]=pred;
		crt->val[crt->n -1]=k;
		DeleteNode(p->leg[idx],k);
	}
	else
	{
		if(p->leg[idx+1]->n > (M-1)/2)
		{
			bnod *crt=p->leg[idx+1];

			while(crt->tip !=frunza)
			{
				crt=crt->leg[0];
			}
			int succ=crt->val[0];
			p->val[idx]=succ;
			crt->val[0]=k;
			DeleteNode(p->leg[idx+1],k);
		}
		else
		{
			merge(p,idx);
			DeleteNode(p->leg[idx],k);
		}
	}
}
void borrowFromPrevious(bnod *&p,int idx)
{
	bnod *stg,*drt;
	stg=p->leg[idx-1];
	drt=p->leg[idx];

	for(int i = drt->n;i > 0;i--)
	{
		drt->val[i]=drt->val[i-1];
	}

	if(drt->tip !=  frunza)
	{
		for(int i=drt->n;i >= 0;i--)
		{
			drt->leg[i+1]=drt->leg[i];
		}
	}
	drt->val[0]=p->val[idx-1];

	if(drt->tip != frunza)
	{
		drt->leg[0]=stg->leg[stg->n];
	}
	p->val[idx-1]=stg->val[stg->n-1];

	stg->n--;
	drt->n++;
}
void borrowFromNext(bnod *&p,int idx)
{
	bnod *stg, *drt;
	stg=p->leg[idx];
	drt=p->leg[idx+1];

	stg->val[stg->n]=p->val[idx];

	if(stg->tip != frunza)
	{
		stg->leg[stg->n +1]=drt->leg[0];
	}
	p->val[idx]=drt->val[0];

	for(int i=1;i<drt->n;i++)
	{
		drt->val[i-1]=drt->val[i];
	}

	if(drt->tip != frunza)
	{
		for(int i=1;i <= drt->n;i++)
		{
			drt->leg[i-1]=drt->leg[i];
		}
	}
	stg->n++;
	drt->n--;
}	
void merge(bnod *&p,int idx)
{
	bnod *childl= p->leg[idx];
	bnod *childr= p->leg[idx+1];
	int t=(M-1)/2;

	childl->val[t]=p->val[idx];

	for(int i=0;i < childr->n;i++)
	{
		childl->val[i + t + 1]=childr->val[i];
	}
	if(childl->tip != frunza)
	{
		for(int i=0;i <= childr->n;i++)
		{
			childl->leg[i+t+1]=childr->leg[i];
		}
	}

	for(int i=idx+1;i < p->n;i++)
	{
		p->val[i-1]=p->val[i];
	}
	for(int i=idx+2; i <= p->n;i++)
	{
		p->leg[i-1]=p->leg[i];
	}

	childl->n+=childr->n+1;
	p->n--;

	delete childr;
}
