#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	unsigned short int n = 0; /* Valeur limite des n premiers enters a sommer */

	unsigned short int i = 0; /* Compteur boucle for */
	unsigned short int sommeFor = 0; /* Somme totale du for */

	unsigned short int j = 0; /* Compteur boucle while */
	unsigned short int sommeWhile = 0; /* Somme totale du while */
	bool check = false; /* check depassement boucle while */

	unsigned short int k = 0; /* Compteur boucle do while */
	unsigned short int sommeDoWhile = 0; /* Somme do while */

	do
	{
		printf("Entrer une valeur limite entiere \n"); /* Message pour recuperer la valeur n */
		scanf_s("%u", &n); /* saisie de la valeur n */
		if ((n < 0) || (n > 362))
		{
			printf("Erreur, entrer un nouveau n\n");
		}
		else
		{
			printf("La valeur de n est: %d\n", n);
			printf("\n");
		}

	} while ((n < 0) || (n > 362));


	/* Debut boucle for */
	for (i = 0; i <= n; i++) /* Parcour des valeurs de 0 a n */
	{
		sommeFor = sommeFor + i; /* Somme des valeurs */
	}
	printf("somme boucle for %d\n", sommeFor);
	printf("Compteur boucle for : %d\n", i);
	/*	FIN boucle for */

	printf("\n");

	/* Debut boucle while */
	while ((j <= n) && (check == false)) /* Parcour des valeurs de 0 a n + check depassement */
	{
		if (65535 - sommeWhile >= j)
		{
			sommeWhile = sommeWhile + j; /* Somme des valeurs */
			j++;
		}
		else
		{
			printf("erreur\n");
			check = true;
		}
	}
	printf("somme boucle while %d\n", sommeWhile);
	printf("Compteur boucle while : %d\n", j);
	/* Fin boucle while */

	printf("\n");

	/* Debut boucle do while */
	do {
		sommeDoWhile = sommeDoWhile + k; /* Somme des valeurs */
		k++;

	} while (k <= n); /* Parcour des valeurs de 0 a n */

	printf("somme boucle do while %d\n", sommeDoWhile);
	printf("Compteur boucle do while : %d\n", k);
	/* Fin boucle while */

	/* Pour un unsigned short int la valeur maximale qui peut etre affcihee est 65535 */
	/* Si on rentre une valeur trop elevee de n, on obtient une valeur au hasard par effet push */



	system("PAUSE");
	return 0;
}
