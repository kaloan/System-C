#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char* argv[])
{
close(0);
close(1);
open(argv[1],O_RDONLY);
open(argv[2],O_CREAT|O_WRONLY,0777);
char buff[1];
while(read(0,buff,1))
{
write(1,buff,1);
}
return 0;
}
