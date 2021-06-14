#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
int main(int argc,char* argv[])
{
 int fd=open(argv[1],O_CREAT,0777);
 close(fd);
 close(1);
 open(argv[1],O_WRONLY);
 if(fork())
 {
  write(1,"HELLO1",6);
 }
 else
 {
  write(1,"HELLO2",6);
 } 
 write(1,"BLABLABLA",9); 
 return 0;
}
