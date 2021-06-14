#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
 int fd=open(argv[1],O_RDONLY);
 int offset=atoi(argv[2]);
 lseek(fd,offset,0);
 char buff[1];
 while(read(fd,buff,1))
 {
  write(1,buff,1);
 }
 return 0;
}
