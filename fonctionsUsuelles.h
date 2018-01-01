
#include "article.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
void initialisationMemoriePartage(int* identifiant,void* pointeur_stock );
ARTICLE** initialisationStock();
ARTICLE** faireAManger(ARTICLE** liste);
void afficheStock(ARTICLE** liste);
void length(ARTICLE ** liste);
void attachementMemoirePartage(int identifiant, void* pointeur_stock);
