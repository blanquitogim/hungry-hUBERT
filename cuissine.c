
#include <unistd.h>
#include <stdlib.h>
#include "fonctionsUsuelles.h"
#include "fonctions_semaphore.h"
#include "article.h"
#define IDENTIFIANT_SEMAPHORE 10
#define MUTEX 1

static int identifiant;



int main(){
	printf("creation pere et fils\n");
	int pid;
	pid= fork();
	printf("initialisation semaphore\n");
	//Création et initialisation du mutex
	create_semaphore(CLEF);
	init_semaphore(IDENTIFIANT_SEMAPHORE,MUTEX); //on initialise un sémaphore privé

		if(pid==0){ //CUISINE
			up(IDENTIFIANT_SEMAPHORE);
			printf("CUISINE\n" );
			void* pointeur_stock; //	adresse d'attachement du segment de mémoire partagée (idem)
			initialisation_MemoriePartage( &identifiant, pointeur_stock, NUMERO_MAX_ARTICLES, CLEF);
			printf("ON COMMENCE À CUISINER! ceci peut prendre un peu de temps\n");
			 pointeur_stock=initialisationStock(pointeur_stock);
			int i=0;
			afficheStock(pointeur_stock,i);
			pointeur_stock=faireAManger(pointeur_stock);
			printf("les repas sont prêts à être vendus\n");
			i=0;
			afficheStock(pointeur_stock,i);
			printf("%p\n", pointeur_stock);
			down(IDENTIFIANT_SEMAPHORE);

		}
		else if(pid>0){// RESTO
			sleep(1);
			open_semaphore(CLEF);
			printf("RESTO\n" );
			int identifiant_pere; //	identificateur du segment de mémoire partagée associé à CLEF (là encore le nom de cette variable n'a rien à voir avec celle du programme A mais son contenu sera évidemment identique)
			void* pointeur_stock_pere; //	adresse d'attachement du segment de mémoire partagée (idem)
			ouverture_MemoriePartage(identifiant_pere, pointeur_stock_pere,NUMERO_MAX_ARTICLES,CLEF);
printf("je demande la permission\n" );
			up(IDENTIFIANT_SEMAPHORE);
			printf("Voici le stock disponible:\n" );
			printf("%p\n",pointeur_stock_pere);
			int j=0;
			afficheStock(pointeur_stock_pere,j);
			down(IDENTIFIANT_SEMAPHORE);
	}

	return 1;
}
//CREATION DE LA MÉMOIRE PARTAGÉE

/*
	//	Je détruis le segment (le segment n'est pas détruit tant qu'au moins un processus est lié au segment)
	shmdt(ptr_mem_partagee_cool smiley;
	//	je quitte le programme
	return 0;
}*/
