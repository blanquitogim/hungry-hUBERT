#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "article.h"

void initialisationMemoriePartage(int* identifiant,void* pointeur_stock ){
    (*identifiant) = shmget(CLEF, NUMERO_MAX_ARTICLES*sizeof(ARTICLE), 0666|IPC_CREAT);  //  je crée un nouveau segment mémoire avec droits d'écriture et de lecture
    printf("Segment correctement créé! \n");
    pointeur_stock = (ARTICLE*)shmat((*identifiant), NULL, 0);    //  J'attache le segment de mémoire partagée identifié par mem_ID au segment de données du processus A dans une zone libre déterminée par le Système d'exploitation
    printf("Segment correctement attaché à un processus\n");
}

ARTICLE** initialisationStock(){
  //j'alou de la memoire pour le tableau d'articles

  ARTICLE* liste[NUMERO_MAX_ARTICLES];
  ARTICLE* article;

  for(int i=0; i<NUMERO_MAX_ARTICLES;i++){
    article=(ARTICLE*)malloc(sizeof(ARTICLE));
    liste[i]= article;
 }

//j'initialise les articles dans le tableau
  for(int i=0; i< NUMERO_MAX_ARTICLES; i++){
    liste[i]->type=i;
    liste[i]->prix= rand()%20;//génération d'un prix aléatoire
    liste[i]->quantite=0;
  }
  return liste;
}


/*for(int i=0; i< num max d'articles, i++){
    if(article[i]< numero max d 1 type d'articles){
      delay // preparation
      acces à memoire partagé-> article +1 Augmentationdu stock(article)
    }
}



void entretenirStock(LISTE_ARTICLES liste,ARTICLE article){

}*/

/*ARTICLE* initialisationStock(){
  //j'alou de la memoire pour le tableau d'articles

  ARTICLE liste[NUMERO_MAX_ARTICLES];
  ARTICLE article;

  for(int i=0; i<NUMERO_MAX_ARTICLES;i++){
    article=(ARTICLE*)malloc(sizeof(ARTICLE));
    liste[i]= article;
 }*/

//j'initialise les articles dans le tableau
  /*for(int i=0; i< NUMERO_MAX_ARTICLES; i++){
    liste[i].type=i;
    liste[i].prix= rand()%20;//génération d'un prix aléatoire
    liste[i].quantite=0;
  }
  return liste;
}*/


ARTICLE** faireAManger(ARTICLE **liste){
liste[0]->quantite=10;
liste[1]->quantite=10;
liste[2]->quantite=10;
liste[3]->quantite=10;
liste[4]->quantite=10;
  /*for(int i=0; i< NUMERO_MAX_ARTICLES; i++){
    while((liste[i]->quantite)< QUANTITE_MAX_PLATS){
      printf("incremente 1 plat\n");
      liste[i]->quantite=liste[i]->quantite+1;
    }
  }*/
return liste;
}

void afficheStock( ARTICLE** liste){
    printf("article %d:          Q :%d\n                     P :%f\n",(*liste)->type ,(*liste)->quantite ,(*liste)->prix );
    printf("article %d:          Q :%d\n                     P :%f\n",(*liste+1)->type ,(*liste+1)->quantite ,(*liste+1)->prix );
     printf("article %d:          Q :%d\n                     P :%f\n",(*liste+2)->type ,(*liste+2)->quantite ,(*liste+2)->prix );
    printf("article %d:          Q :%d\n                     P :%f\n",(*liste+3)->type ,(*liste+3)->quantite ,(*liste+3)->prix );
     printf("article %d:          Q :%d\n                     P :%f\n",(*liste+4)->type ,(*liste+4)->quantite ,(*liste+4)->prix );
      printf("article %d:          Q :%d\n                     P :%f\n",(*liste+5)->type ,(*liste+5)->quantite ,(*liste+5)->prix );
    printf("article %d:          Q :%d\n                     P :%f\n",(*liste+9)->type ,(*liste+9)->quantite ,(*liste+9)->prix );

}

void length(ARTICLE ** liste){
  int compteur=0;
  for(int i=0; i< NUMERO_MAX_ARTICLES; i++){
    if(liste[i]!=NULL){
      compteur++;
    }
  }
  printf("numero d'articles %d\n",compteur);
}
