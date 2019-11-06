#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char mot[30];  // tableau contenant le mot d'origine
	char motclear[30];  // tableau qui contiendra le mot sans les caractères spéciaux (dit propre)
	int i;
	int j = 0;
	printf("Veuillez rentrer un mot pour savoir s'il s'agit d'un palindrome\n");
	printf("Si il y a des caracteres qui ne sont pas des lettres sans accents, ils ne seront pas pris en compte : ");
	scanf_s("%s", mot, (unsigned)_countof(mot));
	int len = strlen(mot);            // initialisation des variables contenant les longueurs des mots
	int lenclear = len;
	_strupr_s(mot,_countof(mot)); // mise en majuscule du mot à tester pour eviter les problèmes de casse
	for (i = 0; i < len; i++) {                    //on parcourt chaque lettre du mot à tester
		if (mot[i] >= 'A' && mot[i] <= 'Z') {      
			motclear[j] = mot[i];                  // si le caractere n'est pas spécial ( lettre majuscule) on le recopie à l'emplacement j du mot propre
			j++;                                   // si on copie un caractere il faut pouvoir ecrire celui d'après à l'emplacement suivant
		}
		else {
			lenclear--;                            // si le caractere est spécial on réduit la longueur du mot propre de 1
			
		}
	}
	motclear[j] = '\0';                    // on indique la fin du mot propre
	for (i = 0; i <= (lenclear/2)+1; i++) {                   // on parcourt la moitié des lettres du mot propre
		if (motclear[i] != motclear[lenclear-1-i]) {          // on teste l'egalite entre le caractere i et son symetrique vis à vis du milieu du mot
			printf("%d %d\n", i,lenclear - 1 - i);
			printf("ce mot n'est pas un palindrome\n"); // si on en détecte au moins 1 il ne s'agit pas d'un palindrome 
			system("pause");
			return 0;   // on arrête donc le programme en cas de palindrome
		}
	}
	printf("ce mot est un palindrome\n");      // s'il ne detecte aucun problème il s'agit d'un palindrome
	system("pause");
}