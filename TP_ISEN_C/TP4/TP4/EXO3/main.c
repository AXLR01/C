#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main()
{
	/******************** VARIABLES ********************/
	char nom[20];
	char prenom[20];
	char sexe;
	/****************** END VARIABLES ******************/
	printf("Nom : ");
	scanf_s("%s", nom, _countof(nom));
	printf("\nPrenom : ");
	scanf_s("%s", prenom, _countof(prenom));
	_cputs("\nSexe : (H)omme/(F)emme");
	printf("\n");
	sexe = toupper(_getch());
	// Affichage du nom et du prenom en fonction du sexe
	if (sexe == 'H')
	{
		printf("\nMonsieur %s %s\n", nom, prenom);
	}
	else if (sexe == 'F')
	{
		printf("\nMadame %s %s\n", nom, prenom);
	}
	else
	{
		printf("\nERROR\n");
	}
	system("pause");
	return 0;
}