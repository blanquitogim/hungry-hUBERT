


#include <unistd.h>
#include <stdlib.h>
#include "fonctionsUsuelles.h"








int main(){



	int pid;
	pid= fork();

	if(pid==0){ //CUISINE
printf("CUISINE\n" );
		int identifiant; //	identificateur du segment de mémoire partagée associé à CLEF (là encore le nom de cette variable n'a rien à voir avec celle du programme A mais son contenu sera évidemment identique)
		void* pointeur_stock; //	adresse d'attachement du segment de mémoire partagée (idem)

		initialisationMemoriePartage( &identifiant, pointeur_stock);
		printf("ON COMMENCE À CUISINER! ceci peut prendre un peut de temps\n");
		ARTICLE** liste;
		liste= initialisationStock();
		afficheStock(liste);

		//liste= faireAManger(&liste);
		printf("les repas sont près à étre vendu\n");
		*((ARTICLE**)pointeur_stock) = *liste;

	}
	else if(pid>0){// RESTO
		sleep(12);
		printf("RESTO\n" );
		int identifiant_pere; //	identificateur du segment de mémoire partagée associé à CLEF (là encore le nom de cette variable n'a rien à voir avec celle du programme A mais son contenu sera évidemment identique)
		void* pointeur_stock_pere; //	adresse d'attachement du segment de mémoire partagée (idem)
		ARTICLE** liste_pere;

		liste_pere= initialisationStock();
		initialisationMemoriePartage(&identifiant_pere, pointeur_stock_pere);
		shmctl (identifiant_pere, IPC_STAT, pointeur_stock_pere);
		*liste_pere=  (ARTICLE**) pointeur_stock_pere;
		printf("Voici le stock disponible:\n" );
		afficheStock(liste_pere);
	}
}

//CREATION DE LA MÉMOIRE PARTAGÉE

/*



	//	Je détruis le segment (le segment n'est pas détruit tant qu'au moins un processus est lié au segment)
	shmdt(ptr_mem_partagee_cool smiley;

	//	je quitte le programme
	return 0;
}*/
