#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
int i=1;
char buff[1];
for(i;i<argc;i++)
{
 int fd=open(argv[i],O_RDONLY);
 while(read(fd,buff,1))
 {
   write(1,buff,1);	
 } 
}
return 0;
}
