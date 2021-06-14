#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
 int i=1;
 for(i;i<argc;i++)
 {
  int pid;
  int status;
  //printf("Testing %d \n",i);
  pid=fork();
  if(pid==0)
  {
   execlp(argv[i],argv[i],0); 
  }
  else
  {
    int temp=wait(&status);
    printf("For the %dth command: %d, %d \n",i,pid,status);
  }
 }
return 0;
}
