#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[]){
    int shm_id;
    char *shm_buff;
    system("ipcs -m");
    if(argc != 2 ){
        printf("USAGE: atshm<identifier>");
        exit(1);
    }
    shm_id = atoi(argv[1]);
    if( (shm_buff = shmat(shm_id,0,0))  < (char *)0){    // attach shares memory into the process , according to  shm_id
    	perror("shmat");
        exit(1);
    }
    printf("segment attached at %p \n",shm_buff);
    system("ipcs -m");
    sleep(3);
    if(shmdt(shm_buff) < 0){ // detattch the shared memory
        perror("shmdt");
        exit(1);
    }
    printf("segment detached \n");
    system("ipcs -m");
    exit(0);

