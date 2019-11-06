#include <stdio.h>
#include <stdlib.h>

/* Creation du type tableau */
typedef struct Tableau
{
	int* elt;// le tableau d�entiers
	int size;// la taille de ce tableau d�entiers
	int eltsCount;// le nombre d��l�ments dans le tableau
}TABLEAU;
TABLEAU NewArray();
int IncrementArraySize(TABLEAU* tab, int IncrementValue);
int SetElement(TABLEAU* tab, int pos, int Element);
int DisplayElements(TABLEAU* tab, int StartPos, int EndPos);
int DeleteElements(TABLEAU* tab, int StartPos, int EndPos);

/* Fonction creation de tableau */
TABLEAU NewArray() {
	TABLEAU tableau;
	tableau.elt = (int*)malloc(100 * sizeof(int));
	tableau.size = 100;
	tableau.eltsCount = 0;
	return tableau;
}

/* Fonction qui augmente la taille d un tableau */
int IncrementArraySize(TABLEAU* tab, int IncrementValue) {
	int* tab2 = (int*)realloc(tab->elt, (tab->size + IncrementValue) * sizeof(int));  // on r�alloue de la m�moire � hauteur de l'ancienne place + la place qu'on veut rajouter
	if (tab2 == NULL) { return(0); }                                                  // si cela echoue on renvoit 0
	tab->elt = tab2;                                                                       // sinon on affecte le nouveal emplacement m�moire
	tab->size += IncrementValue;                                                      //on met � jour la nouvelle taille du tableau
	return (tab->size);
}

/* Fonction qui insere une element a une pos donne */
int SetElement(TABLEAU* tab, int pos, int Element) {
	if (pos < tab->eltsCount) {                             // si la position est d�j� dans le tableau on remplace juste l'ancien contenu par element
		*(tab->elt + pos) = Element;
		return pos;
	}
	int* tab2 = (int*)realloc(tab->elt, (pos + 1) * sizeof(int));     // sinon on r�alloue de la m�moire pour le placer
	if (tab2 == NULL) { return(0); }
	tab->elt = tab2;
	for (int i = tab->eltsCount; i <= pos - 1; i++) {                     // on remplace tous les emplacement entre l'ancienne fin du tableau et la position par 0
		*(tab->elt + i) = 0;
	}
	*(tab->elt + pos) = Element;                                    // on met element � pos
	tab->size = pos + 1;                                              // on met � jour la taille et le nombre d'elements du tableau
	tab->eltsCount = pos + 1;
	return pos;
}

/* Fonction qui affiche une partie du tableau en fonction d une position de debut et de fin */
int DisplayElements(TABLEAU* tab, int StartPos, int EndPos) {
	if ((StartPos >= 0) && (EndPos < tab->size) && (EndPos >= StartPos)) {   // on v�rifie la validit� des param�tres en entr�e
		for (int i = StartPos; i <= EndPos; i++) {                           // on affiche les elements du tableau entre StartPos et EndPos
			printf("%d ", *(tab->elt + i));
		}
		printf("\n\n");
		return 1;
	}
	return 0;
}

/* Fonction qui suprime un element et met a jour la taille du tableau */
int DeleteElements(TABLEAU* tab, int StartPos, int EndPos) {
	int j = 0; // initialisation de l'indice de la liste raccourcie
	int* tab2 = (int*)malloc((tab->size - (EndPos - StartPos) - 1) * sizeof(int));    // on r�alloue la memoire necessaire au traitement
	if (tab2 == NULL) { return(0); }
	for (int i = 0; i <= tab->size - 1; i++) {
		if ((i < StartPos) || (i > EndPos)) {
			*(tab2 + j) = *(tab->elt + i);                                         //on copie chaque element du tableau dans la copie lorsque son indice correspond aux param�tres d'entr�e
			j++;                                                                   //quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et � mesure
		}
	}
	tab->size -= (EndPos - StartPos) + 1;
	tab->eltsCount -= (EndPos - StartPos) + 1;
	tab->elt = tab2;
	return(tab->size);
}

/* Appel des fonctions dans le main */
int main() {
	TABLEAU tableau = NewArray();
	for (int i = 0; i <= tableau.size - 1; i++) {     //initialisation du tableau avec pour valeur l'indice (afin de bien voir les modifications)
		*(tableau.elt + i) = i;
	}
	tableau.eltsCount = 100;
	SetElement(&tableau, 41, 666);
	SetElement(&tableau, 105, 666);                     // on teste l'insertion d'element dans la liste puis en dehors
	DisplayElements(&tableau, 0, tableau.size - 1);      // ils sont bien remplac�s et l'ajout en dehors fonctionne avec les "0" de comblage
	DeleteElements(&tableau, 10, 25);
	DeleteElements(&tableau, 57 - (25 - 10 + 1), 69 - (25 - 10 + 1));                  //on supprime les segments entre 10 et 25 puis 57 et 69 (inclus)
	DisplayElements(&tableau, 0, tableau.size - 1);    // les segments ont bien disparu
	printf("%d\n", tableau.size);                      // taille avant r�alloc
	int a = IncrementArraySize(&tableau, 10);
	printf("%d\n", a);                                 // taille apr�s r�alloc correcte
	system("pause");
	free(tableau.elt);
}
