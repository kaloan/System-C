#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{

int fd1=open(argv[1],O_CREAT|O_TRUNC|O_WRONLY,0777);
char buff[1];
char ch[3];
ch[0]=ch[1]=ch[2]='>';
while(read(0,buff,1))
{
 write(fd1,buff,1);
 if(buff[0]!=9) write(1,buff,1);
 else write(1,ch,3);
}
close(fd1);
return 0;
}
