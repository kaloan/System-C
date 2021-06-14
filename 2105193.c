#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
//int i=2;
int i=1;
char buff[0];
int desc;
int z;
if(argc==1)
{
 while(read(0,buff,1))
 {
  z=write(1,buff,1);	
 }
}
else
{
 int* fds=new int[argc-1];
 for(i=0;i<argc-1;i++)
 {
  fds[i]=open(argv[i+1],O_CREAT|O_TRUNC|O_WRONLY,0777);
 }
 while(read(0,buff,1))
 {
  for(i=1;i<argc;i++)
  {
   z=write(fds[i-1],buff,1);
  } 
 }
}
/*else 
{
 desc=open(argv[1],O_CREAT|O_TRUNC|O_WRONLY,0777);
 while(read(0,buff,1))
 {
  z=write(desc,buff,1);
 }
 close(desc);
 desc=open(argv[1],O_RDONLY);
 int secondDesc;
 for(i;i<argc;i++)
 {
   lseek(desc,0,0);
   secondDesc=open(argv[i],O_CREAT|O_TRUNC|O_WRONLY,0777);
   while(read(desc,buff,1))
   {
    z=write(secondDesc,buff,1);
   }
 }
}*/

return 0;

}
