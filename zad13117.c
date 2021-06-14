#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
 int stat;
 char buff[20];
 if(fork()){
 int pid2=wait(&stat);
 
 int a=getpid();
 itoa(a,buff,10);
 write(1,"Third PID:",10);
 write(1,buff,strlen(buff));
 
 itoa(pid2,buff,10);
 write(1,"Second PID:",11);
 write(1,buff,strlen(buff));
 execlp(argv[3],argv[3],0);
 } 
 else if(fork()){
  int pid1=wait(&stat);
  itoa(pid1,buff,10); 
  write(1,"First PID:",10);
  write(1,buff,strlen(buff));
 
  execlp(argv[2],argv[2],0);
 }
 else{
  execlp(argv[1],argv[1],0);
 }
return 0;
}
