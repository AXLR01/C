#include <stdlib.h>
#include <stdio.h>
#define SIZE 1024


int main()
{
	/******************** VARIABLES ********************/
	char tab[SIZE];
	int letters = 0, nb_words = 0, i = 0;
	float mean = 0;
	/****************** END VARIABLES ******************/
	printf("Ecrivez une phrase : ");
	gets_s(tab, SIZE - 1);
	// Compte le nombre de mots et de lettres tant que la phrase n'est pas terminee
	while (tab[i] != '\0')
	{
		// Comptage des mots
		if ((tab[i] == ' ') || ((tab[i] == 39) && (tab[i + 1] != ' ')))
		{
			++nb_words;
		}
		// Ignore les caracteres speciaux
		else if ((tab[i] < 'A') || ((tab[i] > 'Z') && (tab[i] < 'a')) || (tab[i] > 'z'))
		{
			
		}
		// Compte le nombre de lettres
		else 
		{
			++letters;
		}
		++i;
	}
	++nb_words;
	mean = ((float)letters) / ((float)nb_words);
	printf("\nIl y a %d mots et la longueur moyenne des mots est de %.2f caracteres.\n", nb_words, mean);
	system("pause");
	return 0;
}