#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char mot[30];  // tableau contenant le mot d'origine
	char motclear[30];  // tableau qui contiendra le mot sans les caract�res sp�ciaux (dit propre)
	int i;
	int j = 0;
	printf("Veuillez rentrer un mot pour savoir s'il s'agit d'un palindrome\n");
	printf("Si il y a des caracteres qui ne sont pas des lettres sans accents, ils ne seront pas pris en compte : ");
	scanf_s("%s", mot, (unsigned)_countof(mot));
	int len = strlen(mot);            // initialisation des variables contenant les longueurs des mots
	int lenclear = len;
	_strupr_s(mot,_countof(mot)); // mise en majuscule du mot � tester pour eviter les probl�mes de casse
	for (i = 0; i < len; i++) {                    //on parcourt chaque lettre du mot � tester
		if (mot[i] >= 'A' && mot[i] <= 'Z') {      
			motclear[j] = mot[i];                  // si le caractere n'est pas sp�cial ( lettre majuscule) on le recopie � l'emplacement j du mot propre
			j++;                                   // si on copie un caractere il faut pouvoir ecrire celui d'apr�s � l'emplacement suivant
		}
		else {
			lenclear--;                            // si le caractere est sp�cial on r�duit la longueur du mot propre de 1
			
		}
	}
	motclear[j] = '\0';                    // on indique la fin du mot propre
	for (i = 0; i <= (lenclear/2)+1; i++) {                   // on parcourt la moiti� des lettres du mot propre
		if (motclear[i] != motclear[lenclear-1-i]) {          // on teste l'egalite entre le caractere i et son symetrique vis � vis du milieu du mot
			printf("%d %d\n", i,lenclear - 1 - i);
			printf("ce mot n'est pas un palindrome\n"); // si on en d�tecte au moins 1 il ne s'agit pas d'un palindrome 
			system("pause");
			return 0;   // on arr�te donc le programme en cas de palindrome
		}
	}
	printf("ce mot est un palindrome\n");      // s'il ne detecte aucun probl�me il s'agit d'un palindrome
	system("pause");
}