#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 100
#define TAILLEAJOUT 50
typedef struct heure { int heure; int minute; } HEURE;
int valideTailleBagage(float dim1, float dim2, float dim3);
unsigned short int somme(unsigned short int n);
unsigned short int sommeRecurs(unsigned short int n);
int permuter(int*a, int*b);
int AfficheHeure(HEURE *UneHeure);
int initTab1(int * tab);
int afficheTab1(int *tab);

/* Fonction taille des bagages */
int valideTailleBagage(float dim1, float dim2, float dim3) {
	float tab[] = { dim1,dim2,dim3 };    // création d'un liste avec les dimensions
	float tmp;
	int i;
	int k;
	for (k = 0; k < 2; k++){
		for (i = 0; i < 2; i++) {
			if (tab[i] < tab[i + 1]) {     // tri de la liste terme à terme
				tmp=tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
}
	dim1 = tab[0], dim2 = tab[1], dim3 = tab[2];    // redefinition des dimensions
	if ((dim1 <= 55 && dim2 <= 35 && dim3 <= 25) && (dim1 >=0 && dim2 >=0 && dim3 >=0) ){ // verification des dimensions
		return 1;
		}
	else {
			return 0;
	}
}

/* Fonction somme */
unsigned short int somme(unsigned short int n) {
	int i;
	unsigned short int sum = 0;
	if (n > 361|| n<1) {      // verification de la validité de l'entrée
		return 0;
	}
	for (i = 1; i <= n; i++) { // calcul de la somme
		sum += i;
	}
	return sum;
}

/* Fonction somme recursive */
unsigned short int sommeRecurs(unsigned short int n) {
	if (n > 361 || n<1) {
		return 0;
	}
	return(n+sommeRecurs(n-1));      //addition de chaque terme avec celui d'avant jusqu'à arriver à 1

}

/* Fonction permute avec adresse */
int permuter(int*a, int*b) {
	if ((a == NULL) || (b == NULL)) {
		return 0;
	}
	int tmp;
	tmp = *a;        // passage par variables pointées pour eviter de permuter des varaiables locales
	*a = *b;
	*b = tmp;
	return 1;
}

/* Fonction qui affiche l heur avec les adresses */
int AfficheHeure(HEURE *UneHeure) {
	printf("il est %02d heures %02d \n", UneHeure->heure, UneHeure->minute);  // %02 sert à rajouter des 0 devant l'heure si c'est nécessaire
}

/* Fonction qui remplis le tableau avec les adresses */
int initTab1(int * tab) {
	if (tab == NULL) {
		return 0;
	}
	for (int i = 0; i<=9; i++) {
		*(tab + i) = 0;              // on affecte 0 à la variable pointée par chaque adresse du tableau
	}
	return 10;
}

/* Fonction qui affiche le tableau */
int afficheTab1(int *tab) {
	printf("le tableau est: ");
	for (int i = 0; i <= 9; i++) {
		printf("%d ", *(tab + i));
	}
	printf("\n\n");
}

int initTab2(int *tab, int Size) {   // même résonnement que les fonctions précedentes sauf que l'on passe par des variables pour la fin des boucles
	if (tab == NULL) {
		return 0;
	}
	for (int i = 0; i < Size; i++) {
		*(tab + i) = 0;
	}
	return Size;
}

int afficheTab2(int *tab,int NbElts) {
	if (tab == NULL) {
		return 0;
	}
	printf("le tableau est: ");
	for (int i = 0; i < NbElts; i++) {
		printf("%d ", *(tab + i));
	}
	printf("\n");
	return NbElts;
}

int ajoutElementDansTableau(int **tab, int *Size, int *NbElements, int Element) {
	if (*NbElements<*Size) {                   // si le nombre d'element est inferieur à la taille on peut juste rajouter un élement à la fin sans réallocation
		*(*tab + *NbElements) = Element;
		(*NbElements)++;
		return (*NbElements);
	}
	int *tab2=(int*)realloc(*tab,(*Size + TAILLEAJOUT )* sizeof(int));   // sinon on réalloue de l'espace
	if(tab2==NULL) {return(-1);}                                         // si cela échoue on renvoie-1
	*tab = tab2;
	*(*tab + *NbElements) = Element;                                      // et on ajoute l'element à la fin du tableau
	*Size += TAILLEAJOUT;                                                 // en mettant à jour la taille et le nombre d'elements
	(*NbElements)++;
	return (*NbElements);
}

/* Fonction main appelle toutes les fonctions */
int main() {
	printf("valide doit afficher 1 et affiche %d et invalide doit afficher 0 et affiche %d\n",valideTailleBagage(25,35,45), valideTailleBagage(25, 35, 65));
	printf("somme =%d et somme en recursif =%d\n", somme(200), sommeRecurs(200));
	int a = 5, b = 10;
	permuter(&a, &b);
	printf("a doit valoir 10 et vaut %d et a doit valoir 5 et vaut %d\n", a, b);
	HEURE heure;
	heure.heure = 15, heure.minute = 42;
	AfficheHeure(&heure);
	int MyTab1[10];
	initTab1(MyTab1);
	afficheTab1(MyTab1);
	int MyTab2 = (int *)malloc(TAILLEINITIALE * sizeof(int));
	if (MyTab2 != NULL) {initTab2(MyTab2, TAILLEINITIALE);}
	else {
		printf("mémoire insuffisante");
		return(-1);
	}
	int taille = 100;
	int nb = 100;
	printf("le nombre d'elments doit etre de 101 et est de %d\n",ajoutElementDansTableau(&MyTab2, &taille,&nb, 7));
	afficheTab2(MyTab2,nb);
	system("pause");
	free(MyTab2);
}
