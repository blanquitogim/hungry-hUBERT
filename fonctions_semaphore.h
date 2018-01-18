#ifndef __SEMAPHORE_H_SEMAPHORE__
#define __SEMAPHORE_H_SEMAPHORE__

/************************************************
* \brief     créé le sémaphore : alloue un segment de mémoire accessible par plusieurs processus
* \param key un entier référençant le sémaphore
* \pre Precondition: clé valide
* \result La fonction renvoie l'identifiant du sémaphore si aucune erreur n'est intervenue, sinon renvoie -1
**************************************************/
int create_semaphore(int key);

/************************************************
* \brief     permet d'ouvrir le sémaphore
* \param key un entier référençant le sémaphore
* \pre Precondition: clé valide
* \result La fonction renvoie l'identifiant du sémaphore si aucune erreur n'est intervenue, sinon renvoie -1
* **************************************************/
int open_semaphore(int key);

/************************************************
* \brief     supprime le sémaphore
* \param id un entier représentant l'identifiant du sémaphore
* \pre Precondition: identifiant valide
* \result La fonction renvoie 0 si aucune erreur n'est intervenue, sinon -1
**************************************************/
int remove_semaphore(int id);

/************************************************
* \brief     initie le sémaphore
* \param id un entier représentant l'identifiant du sémaphore
* \param val un entier représentant la valeur initiale que l'on veut donner au sémaphore
* \pre Precondition: identifiant valide
* \result La fonction renvoie 0 si aucune erreur n'est intervenue, sinon -1
**************************************************/
int init_semaphore(int id, int val);

/************************************************
* \brief     opération up libère le sémaphore (rajoute 1 à son opérateur)
* \param id un entier représentant l'identifiant du sémaphore
* \pre Precondition: identifiant valide
* \result La fonction renvoie 0 si aucune erreur n'est intervenue, sinon -1
**************************************************/
int up(int id);

/************************************************
* \brief      opération down demande à récupérer le sémaphore (enlève 1 à son opérateur) et bloque le processus demandeur jusqu'à l'obtention
* \param id un entier représentant l'identifiant du sémaphore
* \pre Precondition: identifiant valide
* \result La fonction renvoie 0 si aucune erreur n'est intervenue, sinon -1
**************************************************/
int down(int id);


/************************************************
* \brief     retourne la valeur du sémaphore
* \param id un entier représentant l'identifiant du sémaphore
* \pre Precondition: identifiant valide
* \result La fonction renvoie 0 si aucune erreur n'est intervenue, sinon -1
**************************************************/
int get_semaphore(int id);



#endif
