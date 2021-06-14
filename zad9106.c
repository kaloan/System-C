#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
int i=0;
while(i<=10)
{
 execlp("wc","wc","-c",argv[1],0);
 i++;
}
return 0;
}
