#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	srand(time(NULL));
	int tab[100];
	int i;
	int x;   // variable servant au stockage de la valeur recherchée
	int flag = 0;    // varaible me servant à detecter les cas, initialisée à zero
	for (i = 0; i <= 99; i++) {
		tab[i]= rand() % 21;             // remplissage du tableau avec des valeurs aléatoires
	}
	char *curseur=tab;         // initialisation d'un pointeur pointant la première valeur du tableau
	printf("entrer la valeur recherchee : ");
	scanf_s("%d", &x);
	for (i = 0; i <= 99; i++) {
		if ((x == *curseur) &&(flag == 1)) {                   // si la valeur i du tableau corespond à la valeur recherchée on l'affiche
				printf(", puis en %d", i);
		}
		if ((x == *curseur) && (flag==0)) {                     //initialement le flag est à zero, il affiche donc le début de la phrase puis passe à 1 pour le reste du programme
			printf("la valeur %d a ete trouvee en %d",x, i);
			flag = 1;
		}	
		curseur++;                                              // on increment le curseur
	}
	if (flag == 0) {
		printf("la valeur %d n'a pas ete trouvee. \n", x);   // si le flag n'est jamais passé à 1 c'est que l'on n'a pas trouvé la valeur
	}
	else {
		printf(".\n");                                     // dans le cas contraire on peut afficher le point de fin de phrase
	}
	system("pause");
}