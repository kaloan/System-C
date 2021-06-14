#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc,char* argv[])
{
 int fd=open(argv[1],O_CREAT|O_WRONLY,0777);
 if(fork())
 {
  write(fd,"HELLO1",6);
 }
 else
 {
  write(fd,"HELLO2",6);
 } 
 return 0;
}
