#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char* argv[])
{
int fc=open(argv[1],O_CREAT,0777);
close(fc);
int i;
for(i=0;i<10;i++){
write(1,"EXAMPLE\n",8);
}
int ocpy=dup(1);
close(1);
open(argv[1],O_WRONLY);
for(i=0;i<10;i++)
{
char str[20];
sprintf(str,"i=%d\n",i);
write(1,str,strlen(str));
}
close(1);
for(i=0;i<10;i++)
{
write(ocpy,"HELLO\n",6);
}
return 0;
}
