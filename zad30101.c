#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
int fd1=open(argv[1],O_RDONLY);
int fd2=dup(fd1);
int i=0;
char buff[1];
char one[1];
one[0]='1';
while(i<5)
{
read(fd1,buff,1);
write(1,buff,1);
write(1,one,1);
read(fd2,buff,1);
write(1,buff,1);
i++;
}
close(fd1);
while(read(fd2,buff,1))
{
write(1,buff,1);
}
return 0;
}
