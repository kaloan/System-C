#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
char buffer[10];
int fd1, fd2;
fd1=open(argv[1],O_RDONLY);
fd2=open(argv[2],O_CREAT|O_WRONLY|O_APPEND,0777);
while(read(fd1,buffer,10)!=0)
{
 int c=write(fd2,buffer,10);
}
return 0;
}
