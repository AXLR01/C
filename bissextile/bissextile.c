#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int year;

printf("enter une annee \n");
scanf("%d",&year);

if (year%4==0)
{
    if (year%100==0)
    {
        if (year%400==0)
        {
            printf("cette annee est bissextile");
        }
        else
        {
            printf("cette annee n'est pas bissextile");
        }

    }
    else
    {
        printf("cette annee n'est pas bissextile");
    }
}
else
{
 printf("cette annee n'est pas bissextile");
}

}

