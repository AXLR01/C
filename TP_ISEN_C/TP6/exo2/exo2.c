#include <stdio.h>
#include <stdlib.h>
#define NbChiffresMax 30
typedef int GrandEntier[NbChiffresMax];
static GrandEntier Produit;                     // definition d'une variable globale contenant notre resulat
static int N=1;                                 // variable donnant l'antécédent de la factorielle

/* réutilisation des mêmes fonctions que l'exercice précédent afin de travailler avec des grand nombres*/
void Initialise(GrandEntier N);
void Initialise(GrandEntier N) {
	for (int i = 0; i < NbChiffresMax; i++) {
		N[i] = 0;
	}
}

int AjouteADroite(GrandEntier N, int c);
int AjouteADroite(GrandEntier N, int c) {
	if (N[0] != 0) { return (-1); }
	for (int i = 0; i<NbChiffresMax - 1; i++) {
		N[i] = N[i + 1];                              /* décallage à gauche des chiffres */
	}
	N[NbChiffresMax - 1] = c;                         //écriture du nouveau chiffre dans la case de droite ainsi libérée
	return(0);
}

void multi(GrandEntier N,int n) {                         // définission de la multiplication pour les grands entiers
	int retenue = 0;
	int res;
	for (int i = NbChiffresMax - 1; i >= 0; i--) {
		res = N[i] * n + retenue;                        // on réutilise le meme principe que l'addition à l'exeption que l'on effectue une multiplication
		retenue = res / 10;
		N[i] = res % 10;
	}

}

void Affiche(GrandEntier N);
void Affiche(GrandEntier N) {
	int flag = 1;
	for (int i = 0; i < NbChiffresMax; i++) {      
		if ((N[i] == 0) && (flag == 1)) {          
			printf(" ");                          
		}
		else {
			flag = 0;
			printf("%d", N[i]);
			if ((i % 3) == 2) {
				printf(" ");
			}
		}
	}
	printf("\n");
}

void factorielle(int n) {
	if (n == N) {                // si l'on veut recalculer une factorielle qu'on vient de calculer, on affiche juste le résultat précédemment stocké
		Affiche(Produit);    // on affiche juste le resultat sans changer N
	}
	if (n<N) {                            //si on veut cacluler une factorielle inférieure à celle précedemment calculée on reprend le calcul du début
		Initialise(Produit);
		AjouteADroite(Produit, 1);        // on met produit égal à 1
		for (int i = 2; i <= n; i++) {
			multi(Produit, i);            // puis on multiplie produit par tous les entiers supérieurs à 1 et inférieurs ou égaux à n
		}
		N = n;                            //on redéfinit N puis on affiche le résultat 
		Affiche(Produit);
	}

	if (n > N) {                             // sinon on réutilise 
		for (int i = N + 1; i <= n; i++) {    // même résonnement qu'au dessus sauf qu'on réutilise produit et qu'on le mutliplie par les indices entre le N précdedent et le nouveau
			multi(Produit, i);
		}
		N = n;
		Affiche(Produit);
	}
}
int blo(int digit) {
	if ((digit >= 0) && (digit <= 9)) { return(digit+'0'); }
	else { return("NUL"); }
}
int main() {
	for (int i = 0; i<=10; i ++) { printf("%d\n",blo(i)); } // jsp ce que ca fait
	Initialise(Produit);
	AjouteADroite(Produit, 1);
	factorielle(1);
	factorielle(2);
	factorielle(13); // lorsqu'on utilisait le programme sans le systeme de grands nombres, on obtenait un resultat faux à partir de 13 
	factorielle(23); // avec cette methode on peut même aller au delà de 13, et si d'aventure on voulait utiliser une factorielle bien supérieure, il suffirait de changer "NbChiffresMax"
	system("pause");
}