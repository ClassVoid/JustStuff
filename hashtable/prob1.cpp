#include <iostream>
#include <cstring>
#include <fstream>
#include "header1.h"
using namespace std;

int main()
{
	ifstream f;
	Nod **ht;
	int n;
	char sir[128];

	f.open("dictionar_termeni_PC.txt");
	cout<<"n=";
	cin>>n;
	ht=init(n);

	while(!f.eof())
	{
		f>>sir;
		insert(ht,sir,n);
	}

	listare(ht,n);

	f.close();
	return  0;
}
