#include <iostream>
#include "Arbore.h"

using namespace std;

int main()
{
	Nod *root = creareArbore();

	// scrieti codul aici
	cout<<"inordine: ";
	inord(root);
	cout<<"\npostordine: ";
	postord(root);
	cout<<"\nafisare pe linie:";
	AfisLinie(root);
	return 0;
}
