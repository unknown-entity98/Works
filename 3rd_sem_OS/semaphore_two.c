#include<stdio.h>
#include<semaphore.h>
#include <pthread.h>
#include <unistd.h>
char msg[1000];
sem_t semaphore;
void * read_message();
void * display_message();


int main()
{
    pthread_t thread_r, thread_w; //a thread is a part of a process, we define 2 threads
    int result1, result2;
    sem_init(&semaphore, 0, 1);
    pthread_create(&thread_r,NULL,read_message,NULL); //assigning 1 thread to 1 process
    pthread_create(&thread_w,NULL,display_message,NULL);

    pthread_join(thread_r,NULL);
    pthread_join(thread_w,NULL);

    return 0;
}
void * read_message()
{
    while(1)
    {
        sem_wait(&semaphore);
        printf("\nEnter a message ");
        scanf("%s",msg);

        sem_post(&semaphore);
        sleep(1);
    }
}
void * display_message()
{
    while(1)
    {
        sem_wait(&semaphore);
        printf("\nmessage is :  %s",msg);
        sem_post(&semaphore);
        sleep(1);
    }
}