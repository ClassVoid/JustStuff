#include <iostream>
#include <fstream>
#include "header1.h"
using namespace std;

int main()
{
	int **mat,n,m,i,j,k,cost;

//citesc matricea de adiacenta din fisier
//n m/i j cost/..
	ifstream file;
	file.open("intrare.txt");

//citesc matricea din fisier
	file>>n>>m;
	mat=zeros(n,m);

	while(!file.eof())
	{
		file>>i>>j>>cost;
		mat[i][j]=cost;
	}

	return 0;
}
