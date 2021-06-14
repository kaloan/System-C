#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
int fc=open(argv[1],O_CREAT,0777);
close(fc);
/*close(1);
open(argv[1],O_WRONLY);*/
int fd1=open(argv[1],O_WRONLY);
close(1);
dup(fd1);
int i=0;
while(i<10){
write(1,"EXAMPLE\n",8);
i++;
}
return 0;
}
