#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 2.4
#define SQUELET
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom :                         Prénom :                               */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compléter code ici pour tableau
	int idx;

	if (rep->nb_elts < MAX_ENREG)
	{
		*(rep->tab + rep->nb_elts) = enr; // on definie le dernier element de la liste avec enr
		rep->nb_elts++;                   // on a donc un element en plus
		rep->est_trie = false;            // la liste n'est pas triee
		modif = true;                     // on a effectue une modification
		return(OK);
	}
	else {
		return(ERROR);
	}

	
#else
#ifdef IMPL_LIST
	// compléter code ici pour Liste
	bool inserted = false;
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}

	}
	else {
		int i = 0;
		while ((i < rep->nb_elts) && (est_sup(enr, (GetElementAt(rep->liste, i)->pers)))) { i++; } // on augmente un compteur tant qu'on est dans la liste et que enr est superieur à l'element compteur de la liste
		InsertElementAt(rep->liste, i, enr); //on insere donc l elment a l empacement compteur, ainsi deja classe
		rep->nb_elts++;                      // on augmente de 1 le nombre d'element
		modif = true;                        // on a modifie
		rep->est_trie = true;                 // la liste est triee
		return(OK);
		
	}


#endif
	
#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	// compléter code ici pour tableau
	if (rep->nb_elts >= 1)		/* s'il y a au moins un element ds le tableau */
	{						/* et que l'indice pointe a l'interieur */
		
		if (indice < rep->nb_elts) {             // si l'indice est dans le tableau
			for (int i = indice; i < rep->nb_elts - 1; i++) {   //on décale chaque element de la liste à partir de celui qu'on veut supprimer vers la gauche
				*(rep->tab + i) = *(rep->tab + i + 1);
			}
		}

		rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
		modif = true;
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// code à compléter ici
	printf("%s, %s                 %s", enr.nom, enr.prenom, enr.tel);  // on affiche simplement avec le nombre d'espace chaque champ vec le filtre %s

} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// code à compléter ici
	// comme fonction affichage_enreg, mais avec présentation alignées des infos
	//on cherche à avoir un affichage constant pour le répertoire donc on utilise le filtre %-30s
	printf("\n| %-30s|%-30s|%-20s", enr.nom, enr.prenom, enr.tel); // permettant de forcer l'aafichage sur 30 caractères, collé à gauche (-)

} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	// code à compléter ici
	if (_stricmp(enr1.nom, enr2.nom) > 0) { return(true); } // on compare d'abord les noms, on retourne vrai si le premier est plus grand que le deuxieme
	if (_stricmp(enr1.nom, enr2.nom) < 0) { return(false); } // on retourne faux sinon
	if (_stricmp(enr1.prenom, enr2.prenom) > 0) { return(true); } // si on arrive là, les noms sont égaux, on recommence donc avec les prénoms
	if (_stricmp(enr1.prenom, enr2.prenom) < 0) { return(false); }

}
 
/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	int flag = 1; // flag servant à compter le nombres de permutations par boucle
	while (flag != 0) {  // on continue jusqu'à ce que le tableau soit trié
		flag = 0; // on remet le flag à zéro
		for (int i = 0; i < rep->nb_elts - 1; i++) { // on parcourt tous les éléments jusqu'a l'avant dernier
			if (est_sup(*(rep->tab + i), *(rep->tab + i + 1))) { // si un element est supérieur à celui d'après
				Enregistrement tmp = *(rep->tab + i);
				*(rep->tab + i) = *(rep->tab + i + 1);            //on les permutent
				*(rep->tab + i + 1) = tmp;
				flag++;                                           // on augmente le flag
	}
}
	}


	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif


	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;


#ifdef IMPL_TAB
	strcpy_s(tmp_nom, MAX_NOM, nom);// on copie le nom dans une variable locale
	_strupr_s(tmp_nom, _countof(tmp_nom)); // puis on la met en majuscule
	ind_fin = rep->nb_elts;       // on s'arrete à la fin du tableau
	for (int i = ind; i < ind_fin; i++) {
		strcpy_s(tmp_nom2, MAX_NOM, rep->tab + i);  // on recopie chaque element du tableau dans une variable temporaire
		_strupr_s(tmp_nom2, _countof(tmp_nom2));    // puis on le met en majuscule
		if (strcmp(tmp_nom, tmp_nom2) == 0) { return i; } // quand les noms sont égaux on retourne l'indice  corerspondant
	}

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	strcpy_s(tmp_nom, MAX_NOM, nom);
	_strupr_s(tmp_nom, _countof(tmp_nom));
	ind_fin = rep->nb_elts;
	for (int i = ind; i < ind_fin; i++) {
		// on utilise la même manière que la liste à l'exeption de la manière dont on recupère les élément
		strcpy_s(tmp_nom2, MAX_NOM, GetElementAt(rep->liste, i)->pers.nom);
		_strupr_s(tmp_nom2, _countof(tmp_nom2));
		if (strcmp(tmp_nom, tmp_nom2) == 0) { return i; }
	}
#endif
#endif


	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char *s)
{
	char tab[MAX_TEL]; // creation d'un tableau qui contiendra le compacté
	int j = 0;         // indice qui sevira pour la recopie
	for (int i = 0; i < strlen(s); i++) { //on parcourt la chaine
		if (s[i] >= '0' && s[i] <= '9') { // si l'element i de la chaine est numérique
			tab[j] = s[i];  // on le recopie à l'indice j du compacté
			j++;   // on augmente j pour copier le suivant à la suite
		}
	}
	tab[j] = '\0';  // caractère de fin de chaine pour dire qu'on a fini la recopie
	strcpy_s(s, MAX_TEL, tab);  // on remplace le nom par la copie
	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE* fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w"); //on ouvre le fichier et on stocke la valeur de retour dans err 
	if (err != 0) { return(ERROR); } //si elle est différente de zéro il y a une erreur
	char buffer[MAX_NOM + MAX_NOM + MAX_TEL + 2]; // on reserve de l'espace pour le nom prenom tel et les séparateurs dans une variable temporaire
	for (int i = 0; i < rep->nb_elts; i++) { // comme le fichier est détruit lors de son ouverture on doit tout réécrire
		//pour chaque i on ecrit dans buffer les informations sous le format souhaité en utilisant le tableau
		sprintf_s(buffer, MAX_NOM + MAX_NOM + MAX_TEL + 2, "%s%c%s%c%s\n", (rep->tab + i)->nom, SEPARATEUR, (rep->tab + i)->prenom, SEPARATEUR, (rep->tab + i)->tel);
		fputs(buffer, fic_rep); //une fois la ligne mise dans buffer on vient l'écrire dans le fichier
	}

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w"); // on utilise la même méthode qu'au dessus à l'exeption de l'ecriture dans buffer
	if (err != 0) { return(ERROR); }
	char buffer[MAX_NOM + MAX_NOM + MAX_TEL + 2];
	for (int i = 0; i < rep->nb_elts; i++) {
		// au lieu d'utiliser le tableau, on passe par la fonction getelementat qui manipule notre liste
		sprintf_s(buffer, MAX_NOM + MAX_NOM + MAX_TEL + 2, "%s%c%s%c%s\n", GetElementAt(rep->liste, i)->pers.nom, SEPARATEUR, GetElementAt(rep->liste, i)->pers.prenom, SEPARATEUR, GetElementAt(rep->liste, i)->pers.tel);
		fputs(buffer, fic_rep);
	}
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE* fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char* char_nw_line;

	_set_errno(0);
	if ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0)
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					* char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
				Enregistrement tmp; // on crée une variable temporaire de type enregistrement
				// ajouter code implemention liste
				if (lire_champ_suivant(buffer, &idx, tmp.nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, tmp.prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, tmp.tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
				InsertElementAt(rep->liste, rep->liste->size, tmp);// une fois qu'on a fini de charger l'element, on l'ajoute à la liste
#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */