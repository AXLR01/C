#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AfficherPlateau(char *Partie, int dbg)
    {
    int i;
    char EnTete[22] = " 012345678\n";
    char caractere;

    printf("\n");
    printf("%s", EnTete);
    printf("0%.9s\n",&Partie[0]);
    printf("1%.9s\n",&Partie[10]);
    printf("2%.9s\n",&Partie[20]);
    printf("3%.9s\n",&Partie[30]);
    printf("4%.9s\n",&Partie[40]);
    printf("5%.9s\n",&Partie[50]);
    printf("6%.9s\n",&Partie[60]);
    printf("7%.9s\n",&Partie[70]);
    printf("8%.9s\n",&Partie[80]);
    printf("%.1s\n",&Partie[90]);
    printf("\n");
    }

void RetirerPierresMortes(char *Partie, char *Territ, int dbg)
{
char ReponseChar;
int Posit;
int PierresRetirees;

RetirerPierres :
            printf("Retirer des pierres? (o/n)\n");
            scanf("%s", &ReponseChar);
            switch (ReponseChar)
                {
                case 'o':
                    PierresRetirees = 0;
                    while (PierresRetirees == 0)
                        {
                        printf("Position de la pierre a retirer ?(00 a 89, ou -1 pour arreter.\n");
                        scanf("%d", &Posit);
                        if (Posit == -1) PierresRetirees = 1;
                        else
                            {
                            if ((Posit < -2) || (Posit > 89) || (Partie[Posit] == ' ') || ((Posit % 10) == 9))
                                printf("Position erronee. Recommencer.\n");
                            else
                                {
                                if (Partie[Posit] == 'N') Territ[Posit] = 'b';
                                if (Partie[Posit] == 'b') Territ[Posit] = 'N';
                                Partie[Posit] = ' ';
                                }
                            }
                        } /* while (PierresRetirees == 0) */
                    break;

                case 'n':
                    PierresRetirees = 1;
                    break;

                default:
                    printf("Reponse incorrecte. Recommencez.\n");
                    goto RetirerPierres;
                } /* switch*/
}

void ChargerHandicap(char *Partie, int dbg)
{
int Posit;
int HandicapEnPlace;
int i = 0;

HandicapEnPlace = 0;

while ((HandicapEnPlace == 0) & (i <9))
    {
    printf("Position de la pierre a placer ?(00 a 89, ou -1 pour arreter.\n");
    scanf("%d", &Posit);
    if (Posit == -1) HandicapEnPlace = 1;
    else
        {
        if ((Posit < -2) || (Posit > 88) || (Partie[Posit] != ' ') || ((Posit % 10) == 9))
             printf("Position erronee. Recommencer.\n");
        else
            Partie[Posit] = 'N';
        }
        i++;
    } /* while (HandicapEnPlace == 0) */
}

void CalculerScore(char *Partie, char *Territ, float *ScoreB, float *ScoreN, int dbg)
{
int i;
float ScoreBl;
float ScoreNo;

ScoreBl = 7.5;
ScoreNo = 0;
for (i = 0; i < 89; i++)
    {
    if (Partie[i] == 'b') ScoreBl++;
    if (Partie[i] == 'N') ScoreNo++;
    if (Territ[i] == 'b') ScoreBl++;
    if (Territ[i] == 'N') ScoreNo++;
    }

*ScoreB = ScoreBl;
*ScoreN = ScoreNo;
}

void ChargerPartie(char *Partie, int dbg)
{
int i;
FILE *PartieFichier;
/* PartieFichier = fopen("/storage/emulated/0/CppDroid/projects/sqdf/partie.txt", "r"); */
PartieFichier = fopen("/home/famille/Bureau/partie.txt", "r");

    if (PartieFichier != NULL)
    {
    i = 0;
while ((fgets(&Partie[10 * i], 12, PartieFichier) != NULL) && (i < 10)) i++;

    fclose(PartieFichier);
 /*    memcpy(&PartieEnCours[0],&Partie[0], 91) ; */

if (dbg==1)
    printf("PartieEncours = %.91s \n", Partie);
}

    else
printf("Impossible d ouvrir partie.txt \n");
}

void SauverPartie(char *Partie, int dbg)
{
FILE *PartieFichier;
/* PartieFichier = fopen("/storage/emulated/0/CppDroid/projects/sqdf/partiebidon.txt", "w"); */
PartieFichier = fopen("/home/famille/Bureau/partie.txt", "w");

if (PartieFichier != NULL)
    {
        fprintf(PartieFichier, "%.91s", Partie);
fclose(PartieFichier);

if (dbg==1)
    printf("PartieEncours = %.91s",Partie);
}


else
    printf("Impossible d ouvrir partie. txt");

}


int CalculerBonus(int Lib, int dbg)
{
int Bonus0Liberte = 200;
int Bonus1Liberte = 100;
int Bonus2Liberte = 50;
int Bonus3Liberte = 10;

int Score = 0;

switch(Lib)
            {
            case 0 :
                {
                Score = Bonus0Liberte;
                break;
                }
            case 1 :
                {
                Score =  Bonus1Liberte;
                break;
                }
            case 2 :
                {
                Score =  Bonus2Liberte;
                break;
                }
            case 3 :
                {
                Score =  Bonus3Liberte;
                break;
                }
            }

return Score;
}


long ScoreDuCoup(int Player1, int Position, char *Partie, int CouleurJ1, int CouleurJ2, int dbg)
{

int Liberte = 10; /* degre de liberte d'une pierre, de 0 à 8 */
int PierreAmie;
int PierreEnnemie;

int Score = 0;

if (Player1==1)
    {
    PierreAmie = CouleurJ1; /* 'b'; */
    PierreEnnemie = CouleurJ2; /* 'n'; */
    }
else
    {
    PierreAmie = CouleurJ2; /* 'n'; */
    PierreEnnemie = CouleurJ1; /* 'b'; */
    }

if (dbg==1)
    printf("Eval du coup pour la position chaine: %d. \n", Position);


/* dans tous les cas, on commence par verifier que la       */
/* pierre ne se retrouve pas completement bloquee par les      */
/* ennemis (suicide)                                        */

switch (Position)
    {

/* ON COMMENCE PAR LES 4 COINS */
    case 0 : /* pierre en haut a gauche */
        {
        if ((Partie[1] == PierreEnnemie) && (Partie[10] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[1] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[2] == PierreAmie)  Liberte--;
            if (Partie[11] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[10] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[11] == PierreAmie)  Liberte--;
            if (Partie[20] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);
        break;
        }




    case 80 : /* pierre en bas a�gauche */
        {
        if ((Partie[70] == PierreEnnemie) && (Partie[81] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[81] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[71] == PierreAmie)  Liberte--;
            if (Partie[82] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[70] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[60] == PierreAmie)  Liberte--;
            if (Partie[71] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);
        break;
        }




    case 8: /* pierre en haut a�droite */
        {
        if ((Partie[7] == PierreEnnemie) && (Partie[18] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[7] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[6] == PierreAmie)  Liberte--;
            if (Partie[17] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[18] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[17] == PierreAmie)  Liberte--;
            if (Partie[28] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);
        break;
        }




    case 88: /* pierre en bas a droite */
        {
        if ((Partie[78] == PierreEnnemie) && (Partie[87] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[78] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[68] == PierreAmie)  Liberte--;
            if (Partie[77] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[87] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[77] == PierreAmie)  Liberte--;
            if (Partie[86] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);
        break;
        }





/* MAINTENANT ON TRAITE LES BORDS */
    case 10:
    case 20:
    case 30:
    case 40:
    case 50:
    case 60:
    case 70: /* Bord gauche */
        {
        if ((Partie[Position-10] == PierreEnnemie) && (Partie[Position+1] == PierreEnnemie)&& (Partie[Position+10] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[Position-10] == PierreEnnemie)
            {
            Liberte = 1;
            if (Partie[Position-9] == PierreAmie)  Liberte--;
            if (Position >19)
                {
                Liberte = Liberte + 1;
                if (Partie[Position-20] == PierreAmie)  Liberte--;
                }
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position+1] == PierreEnnemie)
            {
            Liberte = 3;
            if (Partie[Position-9] == PierreAmie)  Liberte--;
            if (Partie[Position+2] == PierreAmie)  Liberte--;
            if (Partie[Position+11] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position+10] == PierreEnnemie)
            {
            Liberte = 1;
            if (Partie[Position+11] == PierreAmie)  Liberte--;
            }
            if (Position <70)
                {
                Liberte = Liberte + 1;
                if (Partie[Position+20] == PierreAmie)  Liberte--;
                }

        Score = Score + CalculerBonus(Liberte, dbg);
        break;
        }





    case 18:
    case 28:
    case 38:
    case 48:
    case 58:
    case 68:
    case 78: /* Bord droit */
        {
        if ((Partie[Position-10] == PierreEnnemie) && (Partie[Position-1] == PierreEnnemie) && (Partie[Position+10] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[Position-10] == PierreEnnemie)
            {
            Liberte = 1;
            if (Partie[Position-11] == PierreAmie)  Liberte--;
            if (Position <18)
                {
                Liberte = Liberte + 1;
                if (Partie[Position-20] == PierreAmie)  Liberte--;
                }
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position-1] == PierreEnnemie)
            {
            Liberte = 3;
            if (Partie[Position-2] == PierreAmie)  Liberte--;
            if (Partie[Position+9] == PierreAmie)  Liberte--;
            if (Partie[Position-11] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position+10] == PierreEnnemie)
            {
            Liberte = 1;
            if (Partie[Position+9] == PierreAmie)  Liberte--;
            }
            if (Position <70)
                {
                Liberte = Liberte + 1;
                if (Partie[Position+20] == PierreAmie)  Liberte--;
                }

        Score = Score + CalculerBonus(Liberte, dbg);
        break;
        }





    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7: /* Bord haut */
        {
        if ((Partie[Position-1] == PierreEnnemie) && (Partie[Position+1] == PierreEnnemie) && (Partie[Position+10] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[Position-1] == PierreEnnemie)
            {
            Liberte = 1;
            if (Partie[Position+9] == PierreAmie)  Liberte--;
            if (Position > 2)
                {
                Liberte = Liberte + 1;
                if (Partie[Position-2] == PierreAmie)  Liberte--;
                }
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position+10] == PierreEnnemie)
            {
            Liberte = 3;
            if (Partie[Position+9] == PierreAmie)  Liberte--;
            if (Partie[Position+11] == PierreAmie)  Liberte--;
            if (Partie[Position+20] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position+1] == PierreEnnemie)
            {
            Liberte = 1;
            if (Partie[Position+9] == PierreAmie)  Liberte--;
            }
            if (Position <7)
                {
                Liberte = Liberte + 1;
                if (Partie[Position+2] == PierreAmie)  Liberte--;
                }

        Score = Score + CalculerBonus(Liberte, dbg);
        if (dbg==1) printf("Score= %d", Score);
        break;
        }









    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87: /* Bord bas */
        {
        if ((Partie[Position-10] == PierreEnnemie) && (Partie[Position-1] == PierreEnnemie)&& (Partie[Position+1] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[Position+1] == PierreEnnemie)
            {
            Liberte = 1;
            if (Position<87)
                {
                Liberte = Liberte + 1;
                if (Partie[Position+2] == PierreAmie)  Liberte--;
                }
            if (Partie[Position-9] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position-10] == PierreEnnemie)
            {
            Liberte = 3;
            if (Partie[Position-11] == PierreAmie)  Liberte--;
            if (Partie[Position-20] == PierreAmie)  Liberte--;
            if (Partie[Position-9] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position-1] == PierreEnnemie)
            {
            Liberte = 1;
            if (Partie[Position-11] == PierreAmie)  Liberte--;
            }
            if (Position >81)
                {
                Liberte = Liberte + 1;
                if (Partie[Position-2] == PierreAmie)  Liberte--;
                }

        Score = Score + CalculerBonus(Liberte, dbg);
        break;
        }





   default :
        {
        if ((Partie[Position-10] == PierreEnnemie) && (Partie[Position-1] == PierreEnnemie)&& (Partie[Position+1] == PierreEnnemie) && (Partie[Position+10] == PierreEnnemie))
            return -100; /* suicide: la pierre est entouree d'ennemis */
/* On va balayer les pierres ennemies qui sont autour */
        if (Partie[Position-1] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[Position+9] == PierreAmie)  Liberte--;
            if (Partie[Position-11] == PierreAmie)  Liberte--;
            if (Position % 10 > 1 ) /* si pas dans la deuxieme colonne */
                {
                Liberte = Liberte + 1;

                if (Partie[Position-2] == PierreAmie)  Liberte--;
                }
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position-10] == PierreEnnemie)
            {
            Liberte = 3;
            if (Partie[Position-11] == PierreAmie)  Liberte--;
            if (Partie[Position-20] == PierreAmie)  Liberte--;
            if (Partie[Position-9] == PierreAmie)  Liberte--;
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position+1] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[Position+11] == PierreAmie)  Liberte--;
            if (Partie[Position-9] == PierreAmie)  Liberte--;
            if ((Position % 10) < 8)  /* pas dans l'avant-derniere colonne */
                {
                Liberte = Liberte + 1;
                if (Partie[Position+2] == PierreAmie)  Liberte--;
                }
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        if (Partie[Position+10] == PierreEnnemie)
            {
            Liberte = 2;
            if (Partie[Position+9] == PierreAmie)  Liberte--;
            if (Partie[Position+11] == PierreAmie)  Liberte--;
            if (Position <70 )
                {
                Liberte = Liberte + 1;
                if (Partie[Position+20] == PierreAmie)  Liberte--;
                }
            }

        Score = Score + CalculerBonus(Liberte, dbg);

        break;
        }
   } /* switch */


return Score;
}

int TestValiditeCoup(int Player1, int IntersectionChoisie1, int Evaluation, char *Partie, int CouleurJ1, int CouleurJ2,int *PosMeilleur, int *ScoreMeilleur, int dbg)
{

int ValeurCoup; /* Valeur du Coup si joue par l ordinateur */

ValeurCoup = 0;


/* si l'intersection choisie est vide on continue, sinon   */
/* on arrete et on retourne 0.                             */

if (Partie[IntersectionChoisie1] != ' ') return 0;

/* S'il ne s'agit pas d'une evaluation de coup, on place la */
/* pierre                                                   */
if (Evaluation == 0)
   {
   if (dbg  == 1)  printf("Placement de la pierre\n");

    if (Player1 == 1) Partie[IntersectionChoisie1] = CouleurJ1;
    else Partie[IntersectionChoisie1] = CouleurJ2;

    if (Partie[90] == 'N') /* on met a jour la derniere ligne du tableau */
        Partie[90] = 'b';
    else
        Partie[90] = 'N';


    }
/* S'il s'agit d'une evaluation de coup, on calcule la      */
/* valeur du coup, et si c'est le meilleur resultat         */
/* rencontre, on repere le coup comme etant le meilleur.    */
else
   {
   ValeurCoup  = ScoreDuCoup(Player1,IntersectionChoisie1, Partie, CouleurJ1, CouleurJ2, dbg);
   if (ValeurCoup >= *ScoreMeilleur)
       {
       *ScoreMeilleur = ValeurCoup;
       *PosMeilleur = IntersectionChoisie1;
        }
    }

/* S'il ne s'agit pas d'une evaluation de coup, on affiche  */
/* le nouveau plateau de jeu                                */
if (Evaluation == 0) /* on ne modifie pas le plateau pour une simple evaluation */
    {
    AfficherPlateau(Partie, dbg);
    }

return 1;
}

/************************************************************/
/* Main (procedure principale)                              */
/************************************************************/

int main()
    {
    int ValiditeCoup;
    char PartieEnCours[100] = "         \n         \n         \n         \n         \n         \n         \n         \n         \nN\0";
    char Territoire[100] = "         \n         \n         \n         \n         \n         \n         \n         \n         \nN\0"; /* Cette chaine sert a marquer les territoires conquis : b veut dire territoire blanc, N territoire noir */


    int IntersectionChoisie;

    int Joueur1VientDePasser;
    int Joueur2VientDePasser;
    float ScoreNoirs;
    float ScoreBlancs;
    int Reponse;
    char ReponseCaractere;

    /* char CouleurOrdi; */
    char CouleurJoueur1;
    char CouleurJoueur2;

    int JoueurEnCours;

    char TypePartie;  /* O = contre ordinateur */

    int Debug; /* Utilise pour dbgger le programme */

/* Variables utilisees quand on joue contre l ordinateur */
    int PositionMeilleurCoup, ScoreMeilleurCoup;
    int Eval; /* Pour tester un coup sans le jouer */


    ValiditeCoup = 0;


    Debug = 0;
    TypePartie = 'J';

/* on demande si il faut charger une partie */
ChargerFichier:
    printf("Faut-il charger une partie (o/n)? \n");
    scanf("%s", &ReponseCaractere);
    switch (ReponseCaractere)
        {
        case 'o':
            ChargerPartie(PartieEnCours, Debug);
            break;

       case 'n':
Handicap:
           printf("Faut-il prevoir un handicap (o/n)? \n");
           scanf("%s", &ReponseCaractere);
           switch (ReponseCaractere)
               {
               case 'o':
                   ChargerHandicap(PartieEnCours, Debug);
                   break;

               case 'n':
                   break;

              default:
                  printf("Reponse incorrecte.\n");
                  goto Handicap;
              }

           break;

      default:
           printf("Reponse incorrecte.\n");
           goto ChargerFichier;
    }




/* On commence par demander le type de partie: joueur contre*/
/* joueur, ou joueur contre ordinateur.                     */

typedepartie:
    printf("Jouer contre un autre joueur (1) ou contre l ordinateur (2)? \n");
    scanf("%d", &Reponse);
    switch (Reponse)
        {
        case 1:
            Eval = 0;
            CouleurJoueur1 = 'N';
            CouleurJoueur2 = 'b';
       if (Debug==1) printf("PeC90=%c",PartieEnCours[90]);

            if (PartieEnCours[90]=='N') JoueurEnCours = 1;
           else JoueurEnCours = 2;
            break;

        case 2:
            TypePartie = 'O';
            Eval = 1; /* Pour le joueur 2 : evaluer les coups avant de les jouer */
QuiCommence :
            printf("Qui prend les blancs? (Vous (1) ou l'ordinateur (2))\n");
            scanf("%d", &Reponse);
            switch (Reponse)
                {
                case 1:
                    printf("Vous prenez les blancs.\n");
                    CouleurJoueur1 = 'b';
                    CouleurJoueur2 = 'N';
                    /* CouleurOrdi = 'b'; */
                    if (PartieEnCours[90]== 'b')
                        JoueurEnCours = 1;
                    else
                    JoueurEnCours = 2; /* Pour ce type de partie, 2 est toujours l'ordinateur */
                    break;

                case 2:
                    printf("L'ordinateur prend les blancs.\n");
                    /* CouleurOrdi = 'N'; */
                    CouleurJoueur1 = 'b';
                    CouleurJoueur2 = 'N';
                    if (PartieEnCours[90]== 'N')
                        JoueurEnCours = 2;
                    else
                    JoueurEnCours = 1; /* Pour ce type de partie, 2 est toujours l'ordinateur */
                    break;

                default:
                    printf("Reponse incorrecte. Recommencez.\n");
                    goto QuiCommence;
                } /* switch*/

            break;

        default:
           printf("Reponse incorrecte");
           goto typedepartie;
        }

/* On affiche le plateau de depart.                         */
        AfficherPlateau(PartieEnCours, Debug);


    while (ValiditeCoup != 2)
/* Tant que la partie n'est pas finie */
        {
/* on va tester si on doit faire une eval avant de jouer */
        if (JoueurEnCours == 1)
            Eval = 0;
        else
            {
            if (TypePartie == 'O')  Eval = 1;
            else Eval = 0;
            }

        ValiditeCoup = 0; /* par defaut le coup n'est pas valide */
        ScoreMeilleurCoup = 0;
        PositionMeilleurCoup = -1;

/* le JoueurEnCours doit choisir une intersection libre     */
        while (ValiditeCoup == 0) /* tq le JoueurEnCours ne choisit pas une intersection libre */
            {
            if (Eval == 0)
                {
                if (JoueurEnCours == 1)
                    if (CouleurJoueur1 == 'b')
                        printf("Aux blancs de jouer.\n");
                    else
                        printf("Aux noirs de jouer.\n");
                else
                    if (CouleurJoueur2 == 'b')
                        printf("Aux blancs de jouer.\n");
                    else
                        printf("Aux noirs de jouer.\n");

                printf("A quelle position voulez-vous placer une pierre (horizontale, verticale)? (-1= passer, -2= abandon, - 3= sauver la partie et quitter\n");
                scanf("%d", &IntersectionChoisie);
                if ((IntersectionChoisie != -3) && (IntersectionChoisie != -2) && (IntersectionChoisie != -1))

                if (Debug == 1) printf("IntersectionChoisie = %d",IntersectionChoisie);
                }
            else /* if (Eval == 0, on fait donc maintenant eval== 1) */
/* Remarque: si c'est a l'ordinateur de jouer, on fait une  */
/* evaluation de tous les coups possibles (scan de toutes   */
/* les horizontales et horizontales)                        */
/* Cette evaluation est basee sur un systeme de bonus, en   */
/* fonction de l'etouffement des pierres adverses. Une fois */
/* que c'est fait, le meilleur coup possible est repere.    */
                {
                if (JoueurEnCours == 2) /* c est a l'ordi de jouer */
                    {
/* On balaye toutes les intersections possibles */
                    for (IntersectionChoisie = 0; IntersectionChoisie < 89; IntersectionChoisie++)
                        {
       /* on evalue tous les coups pour retenir le meilleur */
                          if (PartieEnCours[IntersectionChoisie] == ' ')
                             ValiditeCoup = TestValiditeCoup(JoueurEnCours, IntersectionChoisie, 1, PartieEnCours, CouleurJoueur1, CouleurJoueur2, &PositionMeilleurCoup, &ScoreMeilleurCoup, Debug);
                         if (Debug == 1)
                             {
                             printf("Position dans chaine %d", IntersectionChoisie);
                             printf("PositionMeilleurCoup = %d \n", PositionMeilleurCoup);
                             }
                        }

                     if (Debug == 1)
                         {
                         printf("Fin de la boucle pour choisir un coup.\n");
                         printf("PositionMeilleurCoup = %d; ",PositionMeilleurCoup);
                         printf("IntersectionChoisie = %d.\n", IntersectionChoisie);
                         }

             /*        if (PositionMeilleurCoup == 90) PositionMeilleurCoup = 89; */

                     IntersectionChoisie = PositionMeilleurCoup;

                     if (PositionMeilleurCoup == -1)
                         IntersectionChoisie = -1; /* Aucun coup n'est possible */

                     if (Debug == 1) printf("IntersectionChoisie apres eval %d \n", IntersectionChoisie+11);
                    }
                }

/* 3 cas de figures sont permis: le JoueurEnCours choisit   */
/* pion, il passe son tour, ou il abandonne                 */
            switch (IntersectionChoisie)
                {
                case -3:  /* sauver et quitter */
                    RetirerPierresMortes(PartieEnCours, Territoire, Debug);
                    SauverPartie(PartieEnCours, Debug);
                    ValiditeCoup = 2;
                    printf("La partie a ete sauvegardee.\n");
                    Joueur1VientDePasser = 1;
                    Joueur2VientDePasser = 1;
                    break;

                case -2: /* abandon */
                    {
                    ValiditeCoup = 2;
                    printf("Quel dommage que vous abandonniez apres une partie si palpitante!\n");
                    CalculerScore(PartieEnCours, Territoire, &ScoreBlancs, &ScoreNoirs, Debug);
                    printf("A bientot! Les blancs ont %.5f points.", ScoreBlancs);
                    printf("Les noirs ont %f points. \n ", ScoreNoirs);
                    if (TypePartie == 'O') Joueur2VientDePasser = 1;
                    break;
                }

                case -1: /* Aucun coup ne peut etre joue: le JoueurEnCours passe son tour */
                   {
                    ValiditeCoup = 1;
                    if (JoueurEnCours == 1)
                        {
                        if (TypePartie == 'O') Joueur2VientDePasser = 1;
                        Joueur1VientDePasser = 1;
                        }
                    else
                        Joueur2VientDePasser = 1;
                    break;
                    }

               default:
                        /* si le coup est valide on le joue */
                  {
                  if (JoueurEnCours == 1)
                      Joueur1VientDePasser = 0;
                  else
                      Joueur2VientDePasser = 0;

                  if (Debug == 1)
                      {
                      printf("Entree dans testValiditeCoup \n");
                      printf("JoueurEnCours %d \n", JoueurEnCours);
                      printf(" IntersectionChoisie %d \n", IntersectionChoisie);
                      }
/* Une fois le coup choisi, on le joue                      */
                if (IntersectionChoisie > 88)
                    printf("Coup invalide! Choisissez une autre intersection ou passez votre tour.\n");
		        else
		            {
		           /*  if ((TypePartie == 'O') && (JoueurEnCours == 2))
		                {
		                sleep(5);
		                printf("L'ordinateur joue ...");
		                } */
                    ValiditeCoup = TestValiditeCoup(JoueurEnCours, IntersectionChoisie, 0, PartieEnCours, CouleurJoueur1, CouleurJoueur2, &PositionMeilleurCoup, &ScoreMeilleurCoup, Debug);
                    if (ValiditeCoup == 0)
                        {
/* le coup n est pas valide. on demande une nouvelle intersection au JoueurEnCours */
                        printf("Coup invalide! Choisissez une autre intersection ou passez votre tour.\n");
                        }
                    else
                        if ((JoueurEnCours!=2) || (TypePartie !='O')) RetirerPierresMortes(PartieEnCours, Territoire, Debug);
                    }
                }
            } /* switch (IntersectionChoisie) */
        } /* while ValiditeCoup  == 0 */




/* Le coup est joue: si les 2 joueurs ont passe, c'est fini */
/* sinon on change de joueur.                               */
        if (JoueurEnCours == 1)
            JoueurEnCours = 2;
       else JoueurEnCours = 1;

    /*    if (PartieEnCours[90] == 'N')
            PartieEnCours[90] = 'b';
        else
            PartieEnCours[90] = 'N'; */

        if ((Joueur1VientDePasser == 1) && (Joueur2VientDePasser == 1))
            {
            CalculerScore(PartieEnCours, Territoire, &ScoreBlancs, &ScoreNoirs, Debug);
            printf("A bientot! Les blancs ont %.5f points.", ScoreBlancs);
            printf("Les noirs ont %.5f points. \n ", ScoreNoirs);
            ValiditeCoup = 2;
            }
        } /* while ValiditeCoup == 2 */

    printf("A bientot pour une nouvelle partie!\n");
    return 0;
    }
