#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int nbr1,nbr2,nbr3,dis,s1,s2=0;
    printf("Calcul d'un discriminant!\n");
    printf("Entrer un nombre enier ou reel\n");
    scanf("%d",&nbr1);
    printf("Entrer un nombre enier ou reel\n");
    scanf("%d",&nbr2);
    printf("Entrer un nombre enier ou reel\n");
    scanf("%d",&nbr3);
    dis=(nbr2*nbr2)-4*nbr1*nbr3;
    if ( dis>0)
    {
        s1=(nbr2+sqrt(dis))/2*nbr1;
        s2=(nbr2-sqrt(dis))/2*nbr1;
        printf("Les solutions sont : %d et %d \n",s1,s2);
    }
    else if ( dis==0)
    {
        s1=nbr2/2*nbr1;
        printf("Les solutions sont : %d \n",s1);
    }
    else
    {
        printf("Discriminant inferieur à zero la flemme frere ");
    }
    return 1;
}
