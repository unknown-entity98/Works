#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

char msg[1000];
//pthread_mutex_t mutex;
sem_t readcount,mutex,wrt;
int v;
void *reading();
void *writing();

void main(){
    pthread_t reader1, reader2, writer1, writer2;//trying to synchronize between 2 readers and 2 writers
    //pthread_mutex_init(&mutex,NULL);
    sem_init(&readcount,4,0);
    sem_init(&mutex,4,1);
    sem_init(&wrt,4,1);

    pthread_create(&reader1,NULL,reading,NULL);//creation of 4 threads
    pthread_create(&reader2,NULL,reading,NULL);
    pthread_create(&writer1,NULL,writing,NULL);
    pthread_create(&writer1,NULL,writing,NULL);

    pthread_join(reader1,NULL);
    pthread_join(reader2,NULL);
    pthread_join(writer1,NULL);
    pthread_join(writer2,NULL);
}
void * writing()
{
    while(1)
    {
    sem_wait(&wrt);
    //beginning of writing part
    printf("\n Enter a writer's name (encouraging the user to be a writer) : ");
    scanf("%s",msg);
    //end of writing part
    sem_post(&wrt);
    //sleep(1);
    }
}
void * reading()
{
    while(1)
    {
        sem_wait(&mutex);
        sem_getvalue(&readcount,&v);//taking the value in variable 'v'
        ++v;//incrementing readcount
        if(v == 1)
        {
            sem_wait(&wrt);
        }
        //beginning of reading part
        printf("\n The reader's name is (reading the 'msg' var) :  %s",msg);
        //end of reading part
        sem_wait(&mutex);
        --v;//decrementing readcount
        if(v==0)
        {
            sem_post(&wrt);
        }
        sem_post(&mutex);
        //sleep(1);
    }
}