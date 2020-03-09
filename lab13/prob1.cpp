#include <iostream>
#include <fstream>
#include "header1.h"
using namespace std;

int main()
{
	
	int i,j,n,m,cost,**mat,k;
	//
	ifstream in("date.in");
	in>>n>>m;
	mat=zeros(n);
	
	for(k=0;k<m;k++)
	{	
		in>>i>>j>>cost;
		mat[i-1][j-1]=cost;	
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	in.close();
	return  0;
}
