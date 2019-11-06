#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>

#define NBMAXNOTES 30 /* taille du tableau passe en define */

void swap(int* a, int* b) /* fonction pour intervertir 2 valeurs */
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(float arr[], int arr2[], int low, int high) /*Fonction pour trouver le pivot du quickSort*/
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index du plus petit element

	for (int j = low; j <= high - 1; j++)
	{
		// Si element plus petit que pivot
		if (arr[j] < pivot)
		{
			i++;    // incremente index du plus petit element
			swap(&arr[i], &arr[j]);
			swap(&arr2[i], &arr2[j]);
			
		}
	}
	swap(&arr[i + 1], &arr[high]);
	swap(&arr2[i + 1], &arr2[high]);

	return (i + 1);
}

void quickSort(float arr[], float arr2[], int low, int high)/* appel des fonctions pour le quickSort */
{
	if (low < high)
	{
		int pi = partition(arr, arr2, low, high);
		quickSort(arr, arr2, low, pi - 1);
		quickSort(arr, arr2, pi + 1, high);
	}
}

int main()
{
	float moy = 0; /* moyenne des notes */
	int nb = 0; /* nombre de note entre */
	int nb2 = 0; /* nombre de note entre pour suivre indice */
	float note[NBMAXNOTES]; /* note entre */
	int indice[NBMAXNOTES] = { 0 }; /* indice des notes */
	char rep = 0; /* stock la rep user*/
	bool arret = false; /* condition sortie du do while*/
	int abs = 0; /* compteur d absent(s) */
	float max = 0; /* valeur max du tableau init a 0 par dafaut */
	float min = 20; /* valeur min du tableau init a 20 par defaut*/
	int i = 0; /* compteur */
	float somme = 0; /* somme des notes du tableau */
	float var = 0; /* calcule variance*/
	float ec = 0; /* calcule ecart type*/	
	float rank[NBMAXNOTES]; /* ctableau de note range */
	int n = sizeof(rank) / sizeof(rank[0]); // definition du quickSort
	int j = 0; /* compteur */
	

	for (i = 0; i < NBMAXNOTES; i++) /* rempli le tableau de -2 */
	{
		note[i] = -2;		
	}

	do
	{ 
		printf("entrez la note no %d :\n", nb+1-abs); /* recuperation des notes */
		scanf_s("%f", &note[nb]);


		if ((note[nb] >= 0) && (note[nb] <= 20)) /* test si note repsect les conditions */
		{
			if (note[nb] > max) /* cherche val max */
			{
				max = note[nb];
			}
			if (note[nb] < min) /* cherche val min */
			{
				min = note[nb];
			}
			indice[nb2] = nb2 + 1;
			nb++; /* incrementation du nombre de note */
			nb2++; /* incrementation indice de note */

		}
		else /* si conditions non respectees */
		{
			note[nb] = -2;
			printf("Vous avez tape une note invalide, l'eleve est-il (A)bsent ou voulez vous arreter la saisie (O)ui (N)on ?\n"); /* demande intention de l utilisateur */
			rep = _getch();/* recup saisie clavier */

			if (rep == 'A') /* s il y a un absent */
			{
				note[nb] = -1; /* ajoute un absent au tableau */
				nb = nb + 1; /* invcremante compteur de note */
				abs++; /* incremente le nombre d abcent*/
				printf("un absent a ete comptee\n");
			}
			if (rep == 'O') 
			{
				arret = true; /* sort du do while */
			}
			if (rep == 'N') 
			{
				printf("reprise du programe\n"); 
			}
		}

	} while ((nb < 30)&&(arret==false)); /* boucle tant que 30 notes sont pas rentrees ou tant que l utilisateur ne dit pas stop*/

	for (i = 0; i < nb; i++) /* parcour le tableau pour les resultats finaux */
	{
		
			if ( (note[i] != -2) && (note[i]!= -1) ) /* condition d une note*/
			{ 
				somme = (somme + note[i]); /* effectue la somme des notes */
			}	
	}	
	moy = somme / ((nb) - abs); 
	i = 0;
	for (i = 0; i < nb; i++) /* parcour le tableu pour les resultats finaux */
	{
		if ( (note[i] != -2) && (note[i]!=-1)) /* condition d une note*/
		{
			var =  var + pow((note[i] - moy), 2);
		}
		
	}
	var = var / (nb-1-abs);
	ec = sqrt(var);

	printf("La moyenne est de %.2f\nIl ya %d absences.\nla plus petite note est %.2f, la plus grande est %.2f,\nL ecart type vaut %.2f\n", moy,abs,min,max,ec);/* affichage des resultats */
	printf("\n");
	printf("No note Valeur note\n");
	for (i = 0; i < nb; i++) /* affiche le tableau non trie */
	{
		if ((note[i] != -2) && (note[i] != -1)) /* condition d une note*/
		{
			rank[j] = note[i]; /* copie note de i dans rank pour ranger rank */
			j++; // parcour rank 
			printf("%d \t %.2f\n",indice[i],note[i]); /* affiche les notes et leur ordre d entre*/
			
		}
	}
	quickSort(rank,indice, 0, n - 1); /* appel fonction de trie*/
	printf("\n");
	printf("tableau trie\n");
	printf("Rang:\t No note \t Valeur note \n");
	for (i = 30; i>0; i--) /* affiche le tableau non trie */
	{
		if ( ( (rank[i] <= 20) && (rank[i] >= 0)) && (indice[i]>0) ) /* condition pour afficher seulement les notes sans addresse tab car quicksort commence par la fin du tableau */
		{
			printf("%d \t %d \t\t %.2f\n", 30 - i, indice[i], rank[i]);
		}
	}	
	return 0;
}
