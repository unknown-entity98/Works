#include <sys/shm.h>
#include <stdio.h>
  
int main()
{
    int key=123;  
    
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    printf("%d",shmid);  
    // shmat to attach to shared memory    
    char *str_write = (char*) shmat(shmid,0,0);
    
    printf("\n Enter the data to write");
    scanf("%s",str_write);
    //gets(str_write);
  
    printf("Data written in memory: %s\n",str_write);
      
    //detach from shared memory 
    shmdt(str_write);
  
    return 0;
}
