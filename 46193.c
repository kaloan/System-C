#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
 int fd=open(argv[1],O_RDONLY);
 char buff[1];
 int counter=0;
 while(read(fd,buff,1))
 {
  write(1,buff,1);
  if(buff[0]=='\n')
  {
    counter++;
  } 
  if(counter==10)
  {
    break;
  }
 }
 return 0;
}
