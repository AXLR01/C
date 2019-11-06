#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	srand(time(NULL));
	int tab[100];
	int i;
	int x;   // variable servant au stockage de la valeur recherch�e
	int flag = 0;    // varaible me servant � detecter les cas, initialis�e � zero
	for (i = 0; i <= 99; i++) {
		tab[i]= rand() % 21;             // remplissage du tableau avec des valeurs al�atoires
	}
	char *curseur=tab;         // initialisation d'un pointeur pointant la premi�re valeur du tableau
	printf("entrer la valeur recherchee : ");
	scanf_s("%d", &x);
	for (i = 0; i <= 99; i++) {
		if ((x == *curseur) &&(flag == 1)) {                   // si la valeur i du tableau corespond � la valeur recherch�e on l'affiche
				printf(", puis en %d", i);
		}
		if ((x == *curseur) && (flag==0)) {                     //initialement le flag est � zero, il affiche donc le d�but de la phrase puis passe � 1 pour le reste du programme
			printf("la valeur %d a ete trouvee en %d",x, i);
			flag = 1;
		}	
		curseur++;                                              // on increment le curseur
	}
	if (flag == 0) {
		printf("la valeur %d n'a pas ete trouvee. \n", x);   // si le flag n'est jamais pass� � 1 c'est que l'on n'a pas trouv� la valeur
	}
	else {
		printf(".\n");                                     // dans le cas contraire on peut afficher le point de fin de phrase
	}
	system("pause");
}