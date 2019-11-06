#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char prenom[20];
	char nom[20];
	char intitule = 'a'; //initialisation de la variable arbitrairement
	printf("Veuillez rentrer votre nom\n");
	scanf_s("%s", nom, (unsigned)_countof(nom));
	printf("Veuillez rentrer votre prenom \n");
	scanf_s("%s", prenom,(unsigned)_countof(prenom));
	printf("sexe ? (H/F)\n");
	intitule=_getch();
	while (intitule != 'H' && intitule != 'F') {  // on demande le sexe jusqu'à ce qu'il soit correct
		intitule = _getch();
	}
	if (intitule == 'H') {
		printf("Monsieur %s %s\n",nom,prenom);
	}
	else {
		printf("Madame %s %s\n", nom, prenom);
	}
	system("pause");
}