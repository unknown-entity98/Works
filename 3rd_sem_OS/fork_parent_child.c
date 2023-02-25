#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
int id;
id=fork();
if(id==0)
 {
 printf("\n I am child  %d",id);
 }
else
 {
 printf("\n I am parent %d",id); 
 }
}
