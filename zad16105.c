#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
int fd1=open(argv[1],O_RDONLY);
int fd2=open(argv[2],O_CREAT|O_WRONLY,0777);
char buff[1];
int br=0;
char line[100];
char cpy[3];
while(read(fd1,buff,1))
{
 line[br]=buff[0];
 br++;
 if(buff[0]=='\n')
 {
  write(1,line,br+1);
  cpy[0]=line[0];
  cpy[1]=line[1];
  cpy[2]=line[2];
  write(fd2,cpy,3);
  br=0;
 }
}
write(fd2,"\n",1);
write(1,"\n",1);
return 0;
}
