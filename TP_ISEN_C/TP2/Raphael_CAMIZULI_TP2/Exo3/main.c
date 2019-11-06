#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	int nombre = 0; /* nombre a traiter */

	do /* demande tant que le nombre est inferieur a 0 ou supp a 100000 */
	{
		printf("Entrer un entier superieur a 0 et inferieur a 10000\n");
		scanf_s("%d", &nombre);
	} while ((nombre > 10000)||(nombre<0));


	/* Solution en 1 instruction */
	if (((nombre % 4 == 0) && (nombre % 100 != 0)) || (nombre % 400 == 0)) /* test les années */
	{
		printf("Ce nombre correspond a une année bisextille\n"); /* si critere remplis */
	}
	else
	{
		printf("Ce nombre n est pas bisextille\n"); /* si critere non remplis */
	}

	/* Solution en plusieurs instructions */
	if (nombre % 4 == 0) /* test si année divisible par 4  */
	{
		if (nombre % 100 != 0)
		{
			printf("bisextille");
		}
		else /* test si année n est pas divisible par 4 et non par 100 */
		{
			if (nombre % 400 == 0) /* test si année divisible par 400 */
			{
				printf("bisextille\n");
			}
			else
			{
				printf("non bisextilles");
			}
		}
	}
	else /* test si le premier if est respecte */
	{
		printf("non bisextille imbrique");
	}

	system("PAUSE");
	return 0;
}
