#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	char buff[100];
	ifstream fs;	
	fs.open("dictionar_termeni_PC.txt");
	if(fs)
	{
		while(!fs.eof())
		{
			fs>>buff;
			cout<<"#"<<buff<<"#\n";
		}
	}
	
	fs.close();
	return 0;
}
