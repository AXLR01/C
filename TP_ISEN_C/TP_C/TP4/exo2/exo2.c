#include <stdio.h>
#include <stdlib.h>
#define SEPARATEUR '/'
#define TAILLETAB1 20

int main (){
	int MyTab1[TAILLETAB1];
	int i;
	int tmp;
	for (i = 1; i <= TAILLETAB1; i++) {
		MyTab1[i - 1] = i;                     // remplissage du tableau avec les entiers de 1 � 20
	}
	for (i = 0; i <= TAILLETAB1 -1; i++) {
		printf("%d%c",MyTab1[i],SEPARATEUR);    // affichage du tableau avec les s�parateurs
	}
	printf("\n");
	char * MyPtr1 = &(MyTab1[TAILLETAB1 -1]); //initialisation du pointeur
	for (i =0; i <= TAILLETAB1 - 1; i++) {
		printf("%d%c", *(MyPtr1-i), SEPARATEUR); // pour chaque valeur de i on affiche le contenu de la variable poinit�e par myptr - i (soit l'element TAILLETAB - i du tableau)
	}

	system("pause");
}