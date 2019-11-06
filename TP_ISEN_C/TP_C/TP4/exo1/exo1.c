#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"
int main() {
	HEURE HeureDebut,HeureFin,Duree;
	HeureDebut.heure = 12; HeureDebut.minute = 30;
	Duree.heure = 0; Duree.minute = 35;
	int s= HeureDebut.minute + Duree.minute; //on calcule le nombre de minutes "totales"
	HeureFin.minute = s%60; // on donne les mintues de l'heure de fin entre 0 et  59
	HeureFin.heure = (HeureDebut.heure + Duree.heure+(s/60))%24;// on ajoute les heures de début, de durée ainsi que les heures des "minutes totales" le tout entre 0 et 23
	printf("l'heure de debut est %02d:%02d\n", HeureDebut.heure, HeureDebut.minute);
	printf("la duree est %02d:%02d\n", Duree.heure, Duree.minute);                              // le %02d sert à ajouter un zero devant le nombre s'il est entre 0 et 9 
	printf("l'heure de fin est %02d:%02d\n", HeureFin.heure, HeureFin.minute);
	system("pause");
}