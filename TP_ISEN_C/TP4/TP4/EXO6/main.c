#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

int afficherTab(int tab[], int tabSize, int nbVal)
{
	int k = 0;
	if ((tabSize >= nbVal) && ((tabSize < SIZE) || (tabSize > 0)) && (nbVal > 0))
	{
		for (int l = 0; l < 10; l++)
		{
			for (int m = 0; m < 10; m++)
			{
				if (tab[k] < 10)
				{
					printf(" %d ", tab[k]);
				}
				else
				{
					printf("%d ", tab[k]);
				}
				k++;
			}
			printf("\n");
		}
		return nbVal;
	}
	else
	{
		return -1;
	}
}

int main()
{
	/******************** VARIABLES ********************/
	int tab[SIZE],mem[SIZE], val, cmpt = 0;		
	char* curseur = &tab[0];
	/****************** END VARIABLES ******************/
	srand(time(NULL));
	// Remplis le tableau de valeurs aleatoires
	for (int i = 0; i < SIZE; ++i)
	{
		tab[i] = rand() % 20 + 1;
		//printf("%d ", tab[i]); // debug
	}
	afficherTab(tab, SIZE, SIZE);
	printf("\n");
	printf("Entrez la valeur recherchee : ");
	scanf_s("%d", &val);
	// Cherche le nombre d'occurence de la valeur dans la liste et memorise leur position
	for (int j = 0; j < SIZE; ++j)
	{
		*curseur = tab[j];
		if (*curseur == val)
		{
			mem[cmpt] = j;
			++cmpt;
		}
		++curseur;
	}
	if (cmpt == 0)
	{
		printf("\n%d n'apparait pas dans la liste.\n", val);
	}
	else
	{
		printf("La valeur %d a ete trouvee en %d", val, mem[0]);
		for (int k = 1; k < cmpt; ++k)
		{
			printf(" puis en %d", mem[k]);
		}
		printf(".\n");
	}
	system("pause");
	return 0;
}