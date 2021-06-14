#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
main(int argc,char* argv[])
{
int pd[2];
if(pipe(pd)==-1)
{
printf("ERROR PIPING!\n");
exit(1);
}
if(fork())
{
close(1);
dup(pd[1]);
close(pd[0]);
close(pd[1]);
execlp(argv[1],argv[1],0);
}
else
{
close(0);
dup(pd[0]);
close(pd[1]);
close(pd[0]);
execvp(argv[2],&argv[2]);
}
}
