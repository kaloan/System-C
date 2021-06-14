#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
int fd1=open(argv[1],O_RDONLY);
int fd2=open(orgv[2],O_CREAT|O_WRONLY,0777);
int rd=0;
char buff[60];
while(rd=read(fd1,))
}
