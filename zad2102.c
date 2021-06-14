#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
 int fd1=open(argv[1],O_RDONLY);
 int fd2=open(argv[2],O_CREAT|O_WRONLY,0777);
 char lnsav[60];
 char buff[1];
 int br=0;
 int i=0;
 char newl[1];
 newl[0]='\n';
 while(read(fd1,buff,1))
 {
  //write(1,buff,1);
  if(buff[0]=='\n')
  {
   //if(br==0) continue;
   if(lnsav[br]=='$')
   {
     write(1,lnsav,br+1);
     write(1,newl,1);
   }
   else
   {
    char num[60];
    int numsz=0;
    int ns=0;
    for(i=0;i<=br;i++)
    {
	if(lnsav[i]>='0'&&lnsav[i]<='9')
        {
	 num[numsz++]=lnsav[i];
         ns=1;
        }
	else if(ns==1) break;
    }
    write(fd2,num,numsz+1);
    write(fd2,newl,1);
   }
   br=0;
  }
  else lnsav[br++]=buff[0];
 }
 close(fd1);
 close(fd2);
 return 0;
}
