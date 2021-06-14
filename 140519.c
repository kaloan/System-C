#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
int desc;
desc=open("wowowo", O_CREAT|O_WRONLY,0777);
int a=write(desc,"123456789ABCDEF", 10);
return 0;
}
