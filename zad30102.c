#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
int fd1=open(argv[1],O_RDONLY);
int fd2=open(argv[1],O_WRONLY);
write(fd2,"hello",5);
int fd3=dup(fd2);
write(fd3,"worlds",6);
char buff[6];
read(fd1,buff,6);
write(1,buff,6);
close(fd2);
write(fd2,"oops",4);
read(fd1,buff,6);
write(1,buff,6);
write(fd3,"oops",4);
return 0;
}
