#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 4096

int main(){
    printf("page size of the system : %d\n",getpagesize());
    int shm_id = shmget(IPC_PRIVATE,BUFFERSIZE,0667); // create a new shared memory
    if( shm_id < 0 ){
        perror("shmget");
        exit(1);
    }//
    printf("Successfully created segment : %d \n",shm_id);
    system("ipcs -m");
    system("ls");
    exit(0);

}
