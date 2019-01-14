#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//D�claration des constantes
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
//Principe : cr�er un programme qui simule le "jeu" du carr� magigue : un pion qui se d�place dans un carr� jusqu'� que celui-ci soit enti�rement remplie
//Entr�e: N.A
//
//Sortie: nMontab
//
//Note :
//***************************
int main(){

//d�claration et initialisation
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
//Principe : initialiser notre tableau et affecter la valeur � chacune de ses cellules
//
//Entr�e: nMonTab
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
//Principe: d�placer le pions en faisant apelle au fonction avancerdroite , avancergauche et corriger
//
//Entr�e : tMonJeton
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
//Principe: d�placer le pions en postion nord est
//
//Entr�e : tMonJeton
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
//Principe: permet de corriger la position de mon jeton lorsque l'il sort des limites du carr�
//
//Entr�e : tMonJeton
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
//Principe: d�placer le pions en position nord ouest
//
//Entr�e : tMonJeton
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
//Principe: Verifier si la case o� se trouve le jeton est vide pour pouvoir ensuite appeler la fonction placer
//
//Entr�e:nMonTab
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
//Entr�e: Recherche vide -> Vrai ou faux si vrai alors placer
//
//Sortie: Valeurs jeton
//
//Note :
//*************************
void Placer(tJeton tMonJeton,int nMonTab[][TAILLE],int ncpt){


            nMonTab[tMonJeton.nY][tMonJeton.nX]=ncpt;

}

//**************************
//Principe: Afficher le tableau gr�ce � deux boucles imbriqu�es
//
//Entr�e:--
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

