#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
char buff[1];
while(read(0,buff,1))
{
 int c=write(1,buff,1);
}
printf("\n");
return 0;
}
