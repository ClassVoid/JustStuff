#include <iostream>
#include <cstring>
#include "header1.h"
using namespace std;

void init(ELEM *&cap)
{
    cap=0;
}

bool IsEmpty(ELEM *cap)
{
    if(cap==0)
    return 1;
    else
    return 0;

}

void push(ELEM *&cap,char val)
{
    ELEM *p;
    
	p=new ELEM;
	p->c=val;
	p->leg=cap;
	cap=p;
}

bool pop(ELEM *&cap,char &val)
{
    ELEM *p;
    if(!IsEmpty(cap))
    {
	p=cap;
	val=cap->c;
	cap=cap->leg;
	delete p;
	return 1;
    }
    else
    {
	return 0;
    }
}

bool top(ELEM *cap,char &val)
{
    if(!IsEmpty(cap))
    {
	val=cap->c;
	return 1;
    }
    else
    return 0;

}

char *conversie(char *s)
{
    int i,k=0;
    char *sf,ch;
    ELEM *cap;
    init(cap);

    sf=new char(strlen(s)+1);//aloc memorie

    for(i=0;i<(int)strlen(s);i++)//incep sa parcurg sirul
    {
	if(s[i]>='0' && s[i]<='9')//daca e cifra
	{
	    sf[k]=s[i];
	    k++;
	}
	else//daca e operator
	{   
	    if(IsEmpty(cap))//stva e goala
	    {
		push(cap,s[i]);//pun in stiva
	    }
	    else//mai am alti operatori in stiva
	    switch(s[i])
	    {
		case '+':
		if(cap->c !='*' && cap->c !='/')//daca nu pun peste * sau /
		{
	    		push(cap,s[i]);
		}
		else//am de a face cu operatori de prioritate mai mare
		{
		    while(!IsEmpty(cap) && cap->c!='(' && (cap->c=='*' || cap->c=='/'))
		    {	
			pop(cap,ch);
			sf[k]=ch;
			k++;
			//scriu operatorii din stiva cu prioritate mai mare
		    }
		    push(cap,s[i]);//dupa pun operatorul in stiva
		}
		break;
		case '-':
		if(cap->c!='*' && cap->c!='/')
		{
			push(cap,s[i]);
		}
		else
		{
		    while(!IsEmpty(cap) && cap->c!='(' && (cap->c=='*' || cap->c=='/'))
		    {
		    pop(cap,ch);
		    sf[k]=ch;
		    k++;//scriu tot ce e in stiva
		    }
		    push(cap,s[i]);
		}
		break;
		case '*':
		    push(cap,s[i]);
		break;
		case '/':
		    push(cap,s[i]);
		break;
		case '(':
		   // if(cap->c=='*' || cap->c=='/')
		    push(cap,s[i]);
		   /* else
		    {
			while(pop(cap,sf[k]))
			{
			k++;
			}
		    }
		    */
		break;
		case ')':
		    while(cap->c!='(')
		    {	
			pop(cap,ch);
			sf[k]=ch;
			k++;
		    }
		    pop(cap,ch);

		break;
		
		default :
		break;
	    }
	}
    }
    while(pop(cap,sf[k]))
    k++;
    sf[k]='\0';
    return sf;
}

int evaluare(char *s)
{
	Stack *p;
	int i=0,a,b;
	initi(p);
	while(s[i]!='\0')
	{
		if(s[i]>='0' && s[i]<='9')
		{
			pushi(p,s[i]-'0');
		}
		else
		{
			popi(p,a);
			popi(p,b);
			switch(s[i])
			{
				case '+':
					pushi(p,a+b);
				break;
				case '-':
					pushi(p,b-a);
				break;
				case '*':
					pushi(p,a*b);
				break;
				case '/':
					pushi(p,b/a);
				break;
				default :
				break;
			}
		}
		i++;
	}
	popi(p,a);
	return a;
}

//stiva de intregi
void initi(Stack *&s)
{
	s=0;
}
void pushi(Stack *&s,int val)
{
	Stack *p=0;

	p=new Stack;
	p->data=val;
	p->leg=s;
	s=p;
}
bool popi(Stack *&s,int &val)
{
	Stack *p=s;
	
	if(p!=0)
	{
		val=p->data;
		s=s->leg;
		delete p;
		return 1;
	}
	return 0;
}
