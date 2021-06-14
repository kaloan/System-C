#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
 //char* commnd=argv[1];
 argv++;
 execvp(argv[1],argv);
 printf("Something :%d", 5);
 return 0;
}
