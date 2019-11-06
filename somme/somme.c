#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int somme =0;
int x =0;
int cmpt=0;


int main()
{

printf("entrer une limite\n");
scanf("%d",&x);
while(cmpt<=x)
{
    somme=somme+cmpt;
    cmpt++;
    printf("somme : %d\n",somme);
}



return 0;
}
