#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
 int linec=0;
 int fd=open(argv[1],O_CREAT|O_WRONLY|O_APPEND,0777);
 char buff[1];
 char tab[1];
 tab[0]=9;
 char newl[1];
 newl[0]='\n';
 while(read(0,buff,1))
 {
  if(linec%2)
  {
   write(1,buff,1);
   if(buff[0]!='\n') write(1,tab,1);
  }
  else
  {
   write(fd,buff,1);
  }
  if(buff[0]=='\n')
  {
   linec++;
  }
 }	
 return 0;
}
