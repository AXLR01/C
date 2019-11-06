#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
int i = 0; // variable compteur
int j = 32; // variable compteur
int k = 0; // variable compteur
float l = 20.0;
int m = 0;

printf("affichage des compteurs:\n cmpt1 = %d\n cmpt2 = %d\n cmpt3 = %d\n cmpt4 = %f\n", i,j,k,l);
printf("\n");

for (i=0; i<=100;i++) // boucle pour aller jusqu'à 100
{
    printf("%d ",i); // affiche mon nombre
}
printf("\n");

for (j=32; j<=127;j++) // boucle pour aller de 32 à 127
{
    printf("%c ",j); // affiche l'ASCII
    k=k+1;
    if (k==16) // verifie que 16 caractère sont passé
    {
        printf("\n"); // retour à la ligne
        k=0;
    }
}

printf("\n");

while (l>=0) // boucle pour répeter mon operation
{
   printf("%.1f ",l); // affiche L avec 1 nombre apres la virgule
    l=l-0.5; // fais décroitre L de 0,5
}

printf("affichage des compteurs en fin:\n cmpt1 = %d\n cmpt2 = %d\n cmpt3 = %d\n cmpt4 = %f\n", i,j,k,l);


for (m=0;m<=90;m=m+10)
{
    printf("%f\n",sin(m*3.14/180));
}
return 0;
}
