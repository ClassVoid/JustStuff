#include <iostream>
#include <cstring>
#include "header3.h"
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

    sf=new char(strlen(s)+1);
    for(i=0;i<(int)strlen(s);i++)
    {
	if(s[i]>='0' && s[i]<='9')
	{
	    sf[k]=s[i];
	    k++;
	}
	else
	{   
	    if(IsEmpty(cap))
	    {
		push(cap,s[i]);
	    }
	    else
	    switch(s[i])
	    {
		case '+':
		if(cap->c !='*' && cap->c !='/')
		{
	    		push(cap,s[i]);
		}
		else
		{
		    while(!IsEmpty(cap) && cap->c!='(')
		    {	
			pop(cap,ch);
			sf[k]=ch;
			k++;
			//scriu tot ce  e in stiva
		    }
		    push(cap,s[i]);
		}
		break;
		case '-':
		if(cap->c!='*' && cap->c!='/')
		push(cap,s[i]);
		else
		{
		    while(!IsEmpty(cap) && cap->c!='(')
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
    ELEM *cap;


}
