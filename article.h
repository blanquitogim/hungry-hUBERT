#include <signal.h>
#ifndef ARTICLE_H
#define ARTICLE_H

#define NUMERO_MAX_RESTO 3
#define MUTEX 1
#define NUMERO_MAX_COMMANDES 10

//	Structure d'un article
#define CLEF 100
#define CLEF_SEM 110

#define CLEF_HUBERT_RESTO 120
#define CLEF_HUBERT_RESTO_SEM 130
#define NUMERO_MAX_ARTICLES 5
#define QUANTITE_MAX_PLATS 10

static int compteurResto;

typedef struct ARTICLE{
	int type;
	int quantite;
  	double prix;
} ARTICLE;

typedef struct COMMANDE{
	int restau ;
  	int pid_client ;
	ARTICLE commande [NUMERO_MAX_ARTICLES];
}COMMANDE;

#endif
