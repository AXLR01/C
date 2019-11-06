#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int nbgen = rand() % 100 + 1;/* genere un nombre entre 1 et 100*/
	//printf("nbgen: %d\n",nbgen ); /* affiche le nombre genere pour debug */
	int tmp = 0; /* stock le nombre de l utilisateur */
	int essai = 0; /* stock le nombre d essais de l utilisateur */

	do /* boucle tant que le nombre n est pas trouve */
	{
		printf("entrer un nombre entier compris entre 1 et 100\n"); /* demande un nombre pour cherche le nombre mystere*/
		scanf_s("%d", &tmp);

		if (nbgen < tmp) /* si le nmbr entrer est plus grand */
		{
			printf("le nombre mystere est plus petit\n");
		}
		if (nbgen > tmp) /* si le nmbr entrer est plus petit */
		{
			printf("le nombre mystere est plus garnd\n");
		}
		if (nbgen == tmp) /* si l utilisateur a trouve */
		{
			printf("Felicitation tu as trouve\n");
			printf("Tu as eu besoin de %d essais\n", essai);
		}
		essai++; /* incrementation des essais */
	} while (nbgen != tmp); /* condition fin de boucle */

	system("PAUSE");
	return 0;
}
