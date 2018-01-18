#include<stdio.h>
#include<sys/types.h>
 #include<sys/ipc.h>
 #include<sys/sem.h>
 


void initialisation_semaphore(int idsem, int val){
  if((semctl(idsem, 0,SET_VAL, val))==­1){
    printf("erreur init\n");
            exit(1);
  }
}

void down(int idsem){
  struct sembuf operation;
  operation.sem_num=0;
  operation.sem_op=­1;
  if(semop(idsem, &operation, 1)==­1){
      printf("erreur ouverture\n");
      return (­1);
   }
}

void up(int idsem){
  struct sembuf operation;
  operation.sem_num=0;
  operation.sem_op=1;
  if(semop(idsem, &operation,1)==-1){
    printf("erreur ouverture\n");
    return (­1);
 }
}
