#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

  
int main()
{
    int key=123;
  
    // shmget returns an identifier in shmid
    // 1024 is the size of the data string
    // 0666 indicates the read write permission
    //IPC_CREAT is the standard key word to create the IPC
    int shmid = shmget(key,1024,0666|IPC_CREAT);
  
    // shmat to attach to shared memory
    //Second parameter has to be a address.By specifying 0 we are letting the kernel to find a space.
    //Third parameter is the flag values.There are four flag values.With a 0 we are unsetting all of them.
    char *str_read = (char*) shmat(shmid,0,0);
  
    printf("Data read from memory: %s\n",str_read);
      
    //detach from shared memory 
    shmdt(str_read);
    
    // destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);
     
    return 0;
}
