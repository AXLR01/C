#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int n=0; int moy=0; int somme =0; int tot = 0;

int main()
{

while (1)
    {
        printf("entrer un nombre ou -1 pour arreter \n");
        scanf("%d",&n);
        if (n == -1)
            {
                printf("FIN");
                return 0;
            }
        tot++;

        somme=somme+n;
        moy=somme/tot;
        printf("moy %d\n",moy);

    }
}
