#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Déclaration des constantes
#define TAILLE 5
#define MIN 1
#define MINCPT 0

//enregistrement
typedef struct tJeton{
    int nX;
    int nY;
}tJeton;

typedef enum Bool{false,true} Bool;

//Prototypes
void initialisation(int nMonTab[][TAILLE]); //va initialiser notre tableau
void avancer(tJeton *tMonJeton,int nMonTab[][TAILLE],int ncpt);
//Qui appelle
void AvancerDroite(tJeton *tMonJeton);
void Corriger(tJeton *tMonJeton);
void AvancerGauche(tJeton *tMonJeton);
//////////////
Bool RechercheVide(tJeton tMonJeton,int nMonTab[][TAILLE]);
void Placer(tJeton tMonJeton,int nMonTab[][TAILLE],int);
void afficher(int nMonTab[][TAILLE]); //permet d'affihcer notre tableau

//**************************
//Principe : créer un programme qui simule le "jeu" du carré magigue : un pion qui se déplace dans un carré jusqu'à que celui-ci soit entièrement remplie
//Entrée: N.A
//
//Sortie: nMontab
//
//Note :
//***************************
int main(){

//déclaration et initialisation
int nMonTab[TAILLE][TAILLE];
int ncpt=0;
char cSaisie;
tJeton tMonJeton={2,1};

initialisation(nMonTab);


for(ncpt=2;ncpt<=TAILLE*TAILLE;ncpt++){

    avancer(&tMonJeton,nMonTab,ncpt);
    printf("Appuyez entrez pour continuer \n");
    afficher(nMonTab);
    scanf("%c",&cSaisie);
    system("cls");
}

     afficher(nMonTab);
return 0;}

//**************************
//Principe : initialiser notre tableau et affecter la valeur à chacune de ses cellules
//
//Entrée: nMonTab
//
//Sortie:1
//
//Note :
//***************************
void initialisation(int nMonTab[][TAILLE]){

int Ncpt=MINCPT;
int NcptB=MINCPT;

for(Ncpt= MINCPT;Ncpt<TAILLE;Ncpt++){
    for(NcptB= MINCPT;NcptB<TAILLE;NcptB++){


        nMonTab[Ncpt][NcptB]=0;

        }
    }

 nMonTab[1][2]=MIN;
}

//**************************
//Principe: déplacer le pions en faisant apelle au fonction avancerdroite , avancergauche et corriger
//
//Entrée : tMonJeton
//
//Sortie: nMonTab
//
//Note :
//***************************
void avancer(tJeton *tMonJeton,int nMonTab[][TAILLE],int ncpt){


    AvancerDroite(&*tMonJeton);
    Corriger(&*tMonJeton);

    if (RechercheVide(*tMonJeton,nMonTab))
        {
           Placer(*tMonJeton,nMonTab,ncpt);
        }
    else
        {
            AvancerGauche(&*tMonJeton);
            Corriger(&*tMonJeton);

                if(RechercheVide(*tMonJeton,nMonTab))
                    {
                        Placer(*tMonJeton,nMonTab,ncpt);
                    }
                else
                {
                    do{
                            AvancerDroite(&*tMonJeton);
                            Corriger(&*tMonJeton);

                      }while(RechercheVide(*tMonJeton,nMonTab));

                    Placer(*tMonJeton,nMonTab,ncpt);
                }


        }

}

//**************************
//Principe: déplacer le pions en postion nord est
//
//Entrée : tMonJeton
//
//Sortie: tMonJeton
//
//Note :
//***************************
void AvancerDroite(tJeton *tMonJeton){

    tMonJeton->nX++;
    tMonJeton->nY--;
}

//**************************
//Principe: permet de corriger la position de mon jeton lorsque l'il sort des limites du carré
//
//Entrée : tMonJeton
//
//Sortie: tMonJeton
//
//Note :
//***************************
void Corriger(tJeton *tMonJeton){

    if (tMonJeton->nX<0){tMonJeton->nX=4;}
    if (tMonJeton->nY<0){tMonJeton->nY=4;}
    if (tMonJeton->nX>4){tMonJeton->nX=0;}
    if (tMonJeton->nY>4){tMonJeton->nY=0;}

}

//**************************
//Principe: déplacer le pions en position nord ouest
//
//Entrée : tMonJeton
//
//Sortie: tMonJeton
//
//Note :
//***************************
void AvancerGauche(tJeton *tMonJeton){

    tMonJeton->nX--;
    tMonJeton->nY--;
}

//**************************
//Principe: Verifier si la case où se trouve le jeton est vide pour pouvoir ensuite appeler la fonction placer
//
//Entrée:nMonTab
//
//Sortie: Vrai ou Faux
//
//Note :
//*************************
Bool RechercheVide(tJeton tMonJeton,int nMonTab[][TAILLE]){

    Bool blTest=false;

    if(nMonTab[tMonJeton.nY][tMonJeton.nX]==0){blTest=true;}

return blTest;}

//**************************
//Principe: Permet de placer le jeton si la case est vide
//
//Entrée: Recherche vide -> Vrai ou faux si vrai alors placer
//
//Sortie: Valeurs jeton
//
//Note :
//*************************
void Placer(tJeton tMonJeton,int nMonTab[][TAILLE],int ncpt){


            nMonTab[tMonJeton.nY][tMonJeton.nX]=ncpt;

}

//**************************
//Principe: Afficher le tableau grâce à deux boucles imbriquées
//
//Entrée:--
//
//Sortie: CMonTab
//
//Note :
//*************************
void afficher(int nMonTab[][TAILLE]){

    int Ncpt= MINCPT;
    int NcptB= MINCPT;

    for(Ncpt=MINCPT;Ncpt<TAILLE;Ncpt++){
        for(NcptB= MINCPT;NcptB<TAILLE;NcptB++){

            printf("%d |",nMonTab[Ncpt][NcptB]);

        }printf("\n");
    }

}

