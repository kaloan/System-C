#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
int fc=open(argv[2],O_RDONLY);
int off=atoi(argv[1]); 
lseek(fc,off,SEEK_SET);
char buff[1];
while(read(fc,buff,1))
{
write(1,buff,1);
}
write(1,"\n",1);
return 0;
}
