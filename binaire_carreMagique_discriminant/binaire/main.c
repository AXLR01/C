#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int nbr = 0;
    int j = 0;
    int i = 7;
    int bin[8] = {0,0,0,0,0,0,0,0};
    // test
    int a,b,c;
    a=1;b=2;c=3;
    printf("valeur de a: %d, adresse de a: %x \nvaleur de b: %d, adresse de b: %x \nvaleur de c: %d, adresse de c: %x \n ", a,&a,b,&b,c,&c);
    // fin test
    printf("Convertisseur binaire sur 8 bits \n");
    printf("entrer un nombre entier positif a covertir \n");
    scanf("%d",&nbr);
    while (nbr != 0)
    {
        bin[i] = nbr%2;
        nbr=floor(nbr/2);
        i=i-1;
    }
    for (j=0;j<8;j++)
    {
       printf("%d",bin[j]);
    }
    return 1;
}
