#include <iostream>
#include <stdio.h>
using namespace std;
main() {
   key_t my_key = ftok("shmfile",65); 
   int shmid = shmget(my_key,1024,0666|IPC_CREAT);
   char *str = (char*) shmat(shmid,(void*)0,0); 
   printf("Data read from memory: %s\n",str);
   shmdt(str);
   shmctl(shmid,IPC_RMID,NULL); 
}