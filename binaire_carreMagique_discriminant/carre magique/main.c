#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int tab  [3][3] = {{6,1,8},{7,5,3},{2,9,4}};
int tab2 [3][3] = {{1,2,3},{1,2,3},{1,2,3}};
int tab3 [3][3] = {{0}};
int function_l(int tab[3][3], int i, int longueur) // return sum ligne
{
  int somme = 0;
  int j =0;
  for (j = 0; j<=longueur-1;j++)
  {somme = somme+ tab[i][j];}
  return somme;
}
int function_c(int tab[3][3], int i, int longueur) // return sum col
{
  int somme = 0;
  int j =0;
  for (j = 0; j<=longueur-1;j++)
  {somme = somme+tab[j][i];}
  return somme;
}
int function_dd(int tab[3][3], int longueur) // return sum diag right
{
  int somme = 0;
  int i =0;
  for (i = 0; i<=longueur-1;i++)
  {somme = somme+tab[i][i];}
  return somme;
}
int function_dg(int tab[3][3], int longueur) // return sum diag left
{
  int somme = 0;
  int j = longueur-1 ;
  int i = 0;
  for (i=0; i<=longueur-1;i++)
  {
      somme=somme+tab[i][j];
      j=j-1;
  }
  return somme;
}

int magic(int tableau,int longueur) // test ksi carre magique
{
    int i = 0;
    int memoire = function_dd(tableau,3);
    if(memoire != function_dg(tableau,3))
    {
        printf(" N'est pas magique\n");
        return 0;
    }
    for (i =0; i<=longueur-1;i++)
    {
        if ( memoire != function_l(tableau,i,3))
        {
            printf(" N'est pas magique\n");
            return 0;
        }
        if ( memoire != function_c(tableau,i,3))
        {
            printf(" N'est pas magique\n");
            return 0;
        }
    }
    printf(" Est magique\n");
    return 1;
}

int exemple1() // test pour exemple 1
{
    int i =0;
    int j = 0;
    printf(" TABLEAU 1\n");
    for ( i = 0;i<=2;i++)
    {
        for( j =0; j <=2; j++)
        {
            printf(" %d",tab[i][j]);
        }
        printf("\n");
    }
    printf(" je suis somme ligne: %d \n",function_l(tab,0,3));
    printf(" je suis somme colonne %d \n",function_c(tab,0,3));
    printf(" je suis somme diagonale droite %d \n",function_dd(tab,3));
    printf(" je suis somme diagonale gauche %d \n",function_dg(tab,3));
    magic(tab,3);
    return 1;
}

int exemple2() // test pour exempole 2
{
    printf(" TABLEAU 2\n");
    int i =0;
    int j = 0;
    for ( i = 0;i<=2;i++)
    {
        for( j =0; j <=2; j++)
        {
            printf(" %d",tab2[i][j]);
        }
        printf("\n");
    }
    printf(" je suis somme ligne: %d \n",function_l(tab2,0,3));
    printf(" je suis somme colonne %d \n",function_c(tab2,0,3));
    printf(" je suis somme diagonale droite %d \n",function_dd(tab2,3));
    printf(" je suis somme diagonale gauche %d \n",function_dg(tab2,3));
    magic(tab2,3);
    return 1;
}

int exemple3() // test pour exempole 2
{
    printf(" TABLEAU 3 TEST\n");
    int i =0;
    int j = 0;
    for ( i = 0;i<=2;i++)
    {
        for( j =0; j <=2; j++)
        {
            printf(" %d",tab3[i][j]);
        }
        printf("\n");
    }
    printf(" je suis somme ligne: %d \n",function_l(tab3,0,3));
    printf(" je suis somme colonne %d \n",function_c(tab3,0,3));
    printf(" je suis somme diagonale droite %d \n",function_dd(tab3,3));
    printf(" je suis somme diagonale gauche %d \n",function_dg(tab3,3));
    magic(tab3,3);
    return 1;
}

int main (void)
{
    int i,j=0;
    exemple1();
    printf("\n");
    exemple2();
    printf("\n");
    printf("TABLEAU 3 \n");
    for (i=0;i<3;i++)
    {
        for (j =0;j<3;j++)
        {
            printf("%d",tab3[i][j]);
        }
        printf("\n");
    }
    remplir(tab3,3);
    printf("TABLEAU 3 APRES \n");
    for (i=0;i<3;i++)
    {
        for (j =0;j<3;j++)
        {
            printf("%d",tab3[i][j]);
        }
        printf("\n");
    }
    exemple3();

}

int remplir(int tab[3][3], int size)
{
    int j=0;
    int k =1;
    int i = floor(size / 2);
	for (k = 1; k<size*size + 1; k++) {
		// case vide : on la remplit
		if (tab[j][i] == 0) {
			tab[j][i] = k;
		}
		// case déjà occupée
		else {
			j = (j + 2) % size; // on passe à la ligne du dessous
			i = ((i - 1)<0) ? size - 1 : i - 1; // on remonte d’une ligne
			tab[j][i] = k;
		}
		j = ((j - 1)<0) ? size - 1 : j - 1; // on remonte d’une ligne
		i = (i + 1) % size; // on avance d’une colonne
	}
    return 1;
}
