#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

typedef enum{false,true} boolean;

#define NbChiffresMax 30

// taille max pour representer un grand entier 
typedef int GrandEntier[NbChiffresMax];

/* representation des grands entiers à l'aide d'un tableau*/
/* les positions qui ne contiennent pas de chiffre significatif */
/* sont initialisées à zero*/

void Initialise(GrandEntier N);
void Initialise(GrandEntier N) {
	for (int i = 0; i < NbChiffresMax; i++) {
		N[i] = 0;                                  // mise à zero de chaque element
	}
}

void Affiche(GrandEntier N);
void Affiche(GrandEntier N) {
	int flag = 1;                                 // indicateur pour savoir si on est dans la zone de 0 avant le nmbre
	for (int i = 0; i < NbChiffresMax; i++) {                          // affichage d'espace à la place des zéros à gauche
		if ((N[i] == 0) && (flag == 1)) {                              //il faut afficher 0
			printf(" ");                                               //Sauf s'il s'agit du digit de droite, au cas ou GrandEntier vaut 0,
		}
		else {
			flag = 0;                    // dès lors qu'il n'y a plus de 0 en début on passe le flag à 0 ainsi on ne rentrera plus dans la premiere condition 
			printf("%d", N[i]);
			if ((i % 3) == 2) {
				printf(" ");          // on affiche un espace tous les 3 digits
			}
		}
	}
	printf("\n");
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

 

/* *********************************************************** */
/* Procedure de saisie d'un grand entier au clavier*/
/* *********************************************************** */

/* FONCTION COMPLETE : NE DOIT PAS ETRE MODIFIEE */
int EntreeClavier(GrandEntier Nombre)
	{
	int NbChiffresLus= 0;
	char car;                 // touche frappée en entrée
	char chiffre[2];          // variable type chaine de caractère pour
							  // conversion de la variable car
							  // en type numérique entier avec atoi() (ASCII to Int)
	int EstUnChiffre =false;
	Initialise(Nombre);             // Nombre prend la valeur zero
	do
		{
		while((car = _getwch()) == 0) {
			car = _getwch();// touche de fonction ou direction enfoncée
		};                                 // lire la touche frappee au clavier 
		
		if (EstUnChiffre = isdigit(car))// s'il s'agit bien d'un chiffre
			{
			printf("%c", car);// echo ecran du chiffre valide 
			chiffre[0] = car; // conversion du caractere en chaine null
			                  // terminated pour utiliser atoi()
			chiffre[1] = 0;

			AjouteADroite(Nombre, atoi(chiffre));// conversion du caractere
			                                     // en valeur numerique et
			NbChiffresLus++;                    // affectation dans le tableau qui
			                                   // contient le grand entier
			}
		else{// s'il s'agit d'un caractère de controle CLEAR (touche 'C' )
			if((car =='C') || (car =='c')) {
			Initialise(Nombre);// effacement des caractères saisies
			printf("\nClear\n");
			EstUnChiffre =true;// pour continuer la saisie de ce nombre
			}
		}
	} 
	while(EstUnChiffre && (NbChiffresLus < NbChiffresMax));
	printf("\n");

	if((car =='X') || (car =='x')) return-1;
	return 0;
	}

int Addition(GrandEntier A, GrandEntier B, GrandEntier result);
int Addition(GrandEntier A, GrandEntier B, GrandEntier result) {
	int res;                   
	int retenue = 0;                                    // remise à zero de la retenue
	for (int i = NbChiffresMax - 1; i >= 0; i--) {
		res = A[i] + B[i] + retenue;                   // resultat "brut" de l'addition des deux digits ainsi que la retenue
		result[i] = res % 10;                          // reste de la division euclidienne par 10 pour obtenir une les unit"s du resultat
		retenue = res/10;                              // resulat de la division pour obtenir le chhiffre des dizaines stocké dans la retenue
	}
	if (retenue == 1) { return(-1); };
	return 0;                                        // dans le cas d'un depassement (retenue > 0) on renvoie -1 sinon 0
}
/* *********************************************************** */
/* Programme principal:         COMPLET: rien à modifier       */
/* *********************************************************** */
int main()
{
	GrandEntier Nb1, Nb2, Nb3;
	int i;
	int Fin =false;
	int Code;// valeur de retour de la fonction EntreeClavier

	while(!Fin)
	{

		if((Code = EntreeClavier(Nb1)) < 0) Fin =true;
		if(!Fin && (Code = EntreeClavier(Nb2) < 0)) Fin =true;
	
		if(!Fin)
		{
			printf("\n  ");
			Affiche(Nb1);
			printf("+ ");
			Affiche(Nb2);
			printf("  ");
			for(i = 0; i < NbChiffresMax; i++)
				{
				if((NbChiffresMax-i) % 3 == 0) printf("-");
				printf("-");
				}
			printf("\n= ");
			Addition(Nb1, Nb2, Nb3);
			Affiche(Nb3);
			printf("\n");
		}
		else
		{
			printf("\n Bye !\n");
		}
	}
	return(EXIT_SUCCESS);
}