#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define CARRE(x) (x)*(x) /* define du calcul du carre */

int main()
{
	int nb = 5; /*initialisation du nombre */
	printf("le carre de 5 est %d\n", CARRE(nb)); /* affichage du carre de nb */
	printf("le carre de nb+1 est %d\n", CARRE(nb+1)); /* pb de priorite de calcule non respecte donc ajouter parentheses */
	return 0;
}
