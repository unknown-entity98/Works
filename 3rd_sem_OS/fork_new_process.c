#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
int id;
id=fork();
if(id==0)
 {
 execlp("/home/sameer/Documents/VS_Code_related/c_codes/othello","othello",NULL);
 }
else
 {
 wait(NULL);
 }
}
