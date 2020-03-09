#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	AVL *root=0;

	root=BuildTree();
	cout<<"\nam iesit din build tree\n";
	Inorder(root);
	cout<<endl;
	PrintInd(root,1);
	Sterg(root);

	return 0;
}
