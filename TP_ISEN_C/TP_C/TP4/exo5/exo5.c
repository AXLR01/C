#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char phrase[1024];
	int i;
	float mot=0;   // compteur de mots
	float moyenne = 0;
	printf("entrez une phrase\n");
	gets_s(phrase,1024);
	for (i = 0; i <= strlen(phrase)-2; i++) { // on parcourt toutes les lettres sauf la dernière (ne pouvant pas contenir un mot)
		if ((phrase[i] == 32) && (phrase[i+1] != 32)) { // on vérifie bien que quand on detecte un espace, il y a un mot après 
			mot++;                                      // si c'est le cas on a detecté un mot donc on incrémente le compteur
		}
		if (phrase[i] != 32) {
			moyenne++;                  // compteur de lettres
		}
	}
	if (phrase[strlen(phrase) - 1] != 32) {
		moyenne++;                      // si le dernier caractere n'est pas un espace on l'ajoute au compteur
	}
	if (phrase[0] == 32) {  // si le premier caractere est un espace le programme compte un mot alors qu'il n'y en a pas
		mot--;              // donc on retire un mot au compteur 
	}
	mot++;    // en realité on comptait le nombre d'espacements et non de mots, il faut donc compter "+1" pour le nombre de mots
	printf("il y a %.0f mots dans la phrase et en moyenne les mots font %.2f lettres\n",mot,moyenne/mot);  // on affiche le nombre de mots et la longueur moyenne des mot 
	system("pause");
}