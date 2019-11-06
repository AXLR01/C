#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int a = 0 ;
int b = 0 ;
int c = 0 ;
int tmp;

printf("enter une valeur a \n");
scanf("%d",&a);

printf("enter une valeur b \n");
scanf("%d",&b);

printf("enter une valeur c \n");
scanf("%d",&c);

if (a>b)
{
    tmp=a;
    a=b;
    b=tmp;
}

if (a>c)
{
    tmp=a;
    a=c;
    c=tmp;
}

if (b>c)
{

    tmp=b;
    b=c;
    c=tmp;
}

printf("je suis a: %d \n",a);
printf("je suis b: %d \n",b);
printf("je suis c: %d \n",c);
return 1;
}
