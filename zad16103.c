#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
int fc=open(argv[1],O_CREAT|O_WRONLY,0777);
write(fc,"abcd-abcd-abcd",14);
close(fc);
int fd1=open(argv[1],O_RDONLY);
int fd2=open(argv[1],O_WRONLY);
lseek(fd2,-2,SEEK_END);
write(fd2,"xyzw",4);
lseek(fd2,5,SEEK_SET);
write(fd2,"12",2);
char buff[20];
read(fd1,buff,20);
write(1,buff,20);
return 0;
}
