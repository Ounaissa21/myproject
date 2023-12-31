#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//============================================================================================================================================================

typedef struct liste liste;
struct liste{
int info;
liste* suiv;
};

//=====================================================================================================================================================================

void ajouterFin (liste **p, int val){

    liste *element = malloc(sizeof(liste));
    element->info = val;
    element->suiv = NULL;

    liste*  tete = *p;

    if(tete == NULL){
        *p = element;
    }

    else {
    while (tete->suiv != NULL){
        tete = tete->suiv;
    }

        tete->suiv = element;
    }}
//=======================================================================================================================================================================

liste* creerliste (){
liste* t = NULL;
int n,val;
    printf("donner la taille de la liste\n");
    scanf ("%d",&n);
     for (int i=1; i++; i<n){
       printf("donner l'element \n");
       scanf ("%d",&val);
       ajouterFin (&t, val);
    }
    return (t);
}

//==============================================================================================================================================================

liste* inverser ( liste** t){
liste* P;
liste* Q;
if (t!= NULL){
    Q = *t;
    P = Q->suiv;
    (*t)->suiv = NULL;
    while (Q!= NULL){
            Q->suiv = *t;
            *t = Q;
            Q = P;
            P = Q->suiv;
    }
}
return (*t);
}

//============================================================================================================================================================

bool estprefixe(liste* l1, liste* l2){
bool pr;
if ((l1 != NULL)&&(l2 != NULL)){
    return (true);
}else if (l2 != NULL){
    pr = true;
    while ((l1!=NULL)&&(pr==true)){
        if (l1->info!=l2->info)
            pr = false;
        l1 = l1->suiv;
        l2 = l2->suiv;
    }
       return (pr);
}
  return (false);
}



//=========================================================================================================================================================

void affiche (liste* t){

if (t!=NULL){
    //affichage du 1 element
    printf ("%d",t->info);
    t = t->suiv;
    while (t!=NULL){
        printf (" -> %d",t->info);
        t = t->suiv;
    }
}
}

//=====================================================================================================================================================================

bool suff (liste* l1, liste* l2){
    l1 = inverser (&l1);
    affiche (l1);
    l2 = inverser (&l2);
    affiche (l2);
    if (estprefixe(l1,l2)==true)
        return (true);
    return (false);
}



//==================================================================================================================================================================

int main()
{
    liste* L1;
    liste* L2;
    L1 = creerliste();
    L2 = creerliste();
    affiche (L1);
    printf ("\n");
    affiche (L2);
    printf ("les 2 listes sont des suffixes : %s\n", suff(L1,L2));
    L1 = inverser (&L1);
    affiche (L1);
    printf ("\n");
    affiche (L2);
    L2 = inverser (&L2);
    return 0;
}