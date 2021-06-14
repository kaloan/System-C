#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
int fc=open(argv[1],O_CREAT,0777);
close(fc);
int fd1=open(argv[1],O_RDONLY);
int fd2=open(argv[1],O_WRONLY);
int fd3=open(argv[1],O_RDWR);
write(fd2,"hello world",11);
char buff[9];
read(fd3,buff,6);
write(1,buff,6);
read(fd1,buff,5);
write(1,buff,5);
write(fd3,"chil",4);
write(fd2,"!!!",3);
read(fd1,buff,9);
write(1,buff,9);
return 0;
}
