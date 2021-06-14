#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
if(!fork())
{
execlp(argv[1],argv[1],0);
}
else{
int a=wait();
printf("Command: %s \n",argv[1]);
}
return 0;
}
