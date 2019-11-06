#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 255

int main()
{
	/******************** VARIABLES ********************/
	char tab[SIZE];
	char tab2[SIZE];
	int cmpt = 0, j = 0;
	/****************** END VARIABLES ******************/
	printf("Test palindrome : ");
	scanf_s("%s", tab, _countof(tab));
	// Mettre tout les caracteres en majuscule et memorise la position de la fin du mot
	for (int i = 0; i < SIZE; ++i)
	{
		tab2[i] = toupper(tab[i]);
		if (tab[i] == '\0')
		{
			cmpt = i;
		}
	}
	//printf("\n%d\n", cmpt); // debug
	// Teste si le mot est un palindrome
	while (j <= (cmpt - 1 - j))
	{
		if (tab2[j] != tab2[cmpt - 1 - j])
		{
			printf("\n%s n'est pas un palindrome.\n", tab);				
			return 1;
		}
		++j;
	}
	printf("\n%s est un palindrome.\n", tab);
	system("pause");
	return 0;
}