#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
int fc=open(argv[1],O_CREAT,0777);
close(fc);
/*close(1);
open(argv[1],O_WRONLY);*/
int fd1=open(argv[1],O_WRONLY);
write(fd1,"abc",3);
close(fd1);
close(1);
fd1=open(argv[1],O_WRONLY);
execlp("echo","echo");
return 0;
}
