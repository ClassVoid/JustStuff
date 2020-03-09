#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	char s[128],*sf;
	int rez;

	cout<<"introduceti ecuatia\n";
	cin>>s;
	sf=conversie(s);
	cout<<sf<<endl;
	rez=evaluare(sf);
	cout<<"rez="<<rez<<endl;

	delete sf;
	return 0;
}
