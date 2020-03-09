#include <cstring>
#include <iostream>
#include "header3.h"
using namespace std;

int main()
{
    char s[128],*sf,*ss;
    
    cout<<"introduceti ecuatia\n";
    cin>>s;
    ss=new char[strlen(s)];
    strcpy(ss,s);
    sf=conversie(ss);
    cout<<"\nexpresia este\n"<<sf<<endl;
    
    delete ss;
    return 0;
}
