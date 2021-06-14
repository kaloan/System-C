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
write(fd3,"hello",5);
char buff[6];
write(fd2,"worlds",6);
read(fd1,buff,6);
write(1,buff,6);
close(fd2);
write(fd3,"oops",4);
char buff2[6];
read(fd1,buff2,6);
write(1,buff2,6);
return 0;
}
