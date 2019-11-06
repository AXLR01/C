#include <stdlib.h>
#include <stdio.h>
#include "tp4.h"

int main()
{
	/******************** VARIABLES ********************/
	HEURE HeureDebut, HeureFin, Duree;
	HeureDebut.heure = 12; HeureDebut.minute = 30; // definit heure et minute de la variable HeureDebut
	HeureFin.heure = 00; HeureFin.minute = 00;     // definit heure et minute de la variable HeureFin
	Duree.heure = 00; Duree.minute = 45;           // definit heure et minute de la variable Duree
	/****************** END VARIABLES ******************/
	// Calcul de heure de HeureFin
	HeureFin.heure = (HeureDebut.heure + Duree.heure + ((int)(HeureDebut.minute + Duree.minute) / 60)) % 24;
	// Clacul de minute de HeureFin
	HeureFin.minute = (HeureDebut.minute + Duree.minute) % 60;
	printf("HeureDebut > %d:%d\n", HeureDebut.heure, HeureDebut.minute);
	printf("Duree      > %d:%d\n", Duree.heure, Duree.minute);
	printf("HeureFin   > %d:%d\n", HeureFin.heure, HeureFin.minute);
	system("pause");
	return 0;
}