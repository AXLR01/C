#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
	unsigned int nb = 2868838400; /* nombre a tester */
	int nbbit = log(nb) / log(2) + 1; /* calcule du nbr de bit pour coder nb */
	int i = 0; /* compteur */
	int bit = 0; /* check bit */

	printf("la taille d'un entier est %d\n", sizeof(nb));
	printf("le nombre de bit est %d\n", nbbit);

	for(i=0;i<nbbit;i++) /* parcour les bits de nb */
	{
		bit = nb & 1 << i; /* teste le i eme et decale de i */
		if (bit != 0)
		{
			printf("bit %2d : ON\n", i); /* affiche ON si le bit est a 1 */
		}
		else
		{
			printf("bit %2d : OFF\n", i); /* affiche OFF si le bit est a 0 */
		}		
	}

	printf("Bye !"); /* message de courtoisie */
	return 0;
}
