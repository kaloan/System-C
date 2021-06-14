#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
 execlp("ls","ls","-l","/home/KN");
 return 0;
}
