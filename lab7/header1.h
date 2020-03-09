#define M 30
struct ELEM{
	char *sir;
	ELEM *urm;
};

ELEM **InitHT(int n);
int fc(char *sir);
ELEM *SearchHT(ELEM **ht,char *sir);
bool InsertHT(ELEM **&ht,char *sir);
void afis(ELEM *cap);
void sterg(ELEM **&ht);
