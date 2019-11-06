#include <stdlib.h>
#include <stdio.h>
#define SEPARATEUR '/'
#define TAILLETAB1 20

int main()
{
	/******************** VARIABLES ********************/
	int MyTab1[TAILLETAB1];
	char* MyPtr = TAILLETAB1 - 1;
	char ptr;
	int val;
	/****************** END VARIABLES ******************/
	// Affichage de tab[0] à tab[19] 
	for (int i = 0; i < TAILLETAB1; ++i)
	{
		MyTab1[i] = i + 1;
		printf("%d%c", MyTab1[i], SEPARATEUR);
	}
	printf("\n");
	// Affichage de tab[19] à tab[0] avec un pointeur
	for (int j = 0; j < TAILLETAB1; ++j)
	{
		ptr = MyPtr;
		val = *(MyTab1 + ptr);
		printf("%d%c", val, SEPARATEUR);
		--MyPtr;
	}
	printf("\n");
	system("pause");
	return 0;
} 