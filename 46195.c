#include<stdio.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
 int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0777);
 char buff[1];
 int lWasNum=0;
 while(read(0,buff,1))
 {
  /*if(buff[0]=='n')
  {
    lineNum++;
  }*/
  if(buff[0]>='0'&&buff[0]<='9')
  {
    buff[0] = '*';
    lWasNum=1;
  }
  else 
  {
   //if(lWasNum)
   //{
    // printf("Censored on line: %d \n",lineNum);    
   //}  
   lWasNum=0;
  }
  write(fd,buff,1); 
  write(1,buff,1);
 }
 return 0;
}
