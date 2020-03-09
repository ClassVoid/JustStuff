#include <iostream>
#include <fstream>
#include <cstring>
#include "header1.h"
using namespace std;

int main()
{
	ELEM **ht=0;
	ifstream in;
	//problema cu inchiderea de fisier
	char buff[100];
	
	ht=InitHT(M);

	in.open("dictionar_termeni_PC.txt");
	if(in)
	{
		while(!in.eof())
		{
			in>>buff;
			cout<<"#"<<buff<<"#";
			if(InsertHT(ht,buff))
			{
				cout<<"=inserat";
			}
			else
			{
				cout<<"=neinserat";
			}
			cout<<endl;
		}
	}


	cout<<"\nDE AICI AFISEZ DIN HASH\n";
	for(int i=0;i<M;i++)
	{
		afis(ht[i]);
		
	}

	sterg(ht);
	ht=0;
	in.close();
	return 0;
}

