#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
 argv++;
 execvp(argv[0],argv);
 return 0;
}
