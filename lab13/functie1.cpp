#include "header1.h"
using namespace std;

int **zeros(int n)
{
	int **a=0;
	int i,j;

	a=new int*[n];

	for(i=0;i<n;i++)
	{
		a[i]=new int[n];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}

	return a;
}
