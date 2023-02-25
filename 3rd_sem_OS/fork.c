#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int id;
    id = fork();
    if(id == 0){
        execlp("/bin/ls","ls",NULL);
    }
    else{
        wait(NULL);
    }
}