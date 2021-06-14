#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
int main(int argc,char* argv[])
{
 int fd=open(argv[1],O_CREAT,0777);
 close(fd);
 if(fork())
 {
  int s=dup(1);
  close(1);
  open(argv[1],O_WRONLY);
  int st;
  wait(&st);
  write(1,"HELLO1",6);
  close(1);
  dup(s);
 }
 else
 {
  int fd2=open(argv[1],O_WRONLY);
  int st;
  wait(&st);
  write(fd2,"HELLO2",6);
 }
 
 write(1,"BLABLABLA",9); 
 return 0;
}
