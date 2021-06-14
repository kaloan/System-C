#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
char buff[100];
int cstart=-1;
int cend=-1;
int i;
int bg=0;
int stat;
int a;
while(true)
{ 
 bg=0;
 cstart=-1;
 cend=-1;
 write(1,"MYPROMPT>",9);
 read(0,buff,100);
 if(buff[0]='\n')
 {
  //write(1,"\n",1);
  continue;
 }
 for(i=0;i<100;i++)
 {
  if(buff[i]!=' '&&buff[i]!='\t'&&buff[i]!='\n')
  {
   cstart=i;
   break;
  }
 }
 if(cstart==-1)
 {
  write(1,"INPUTCOMMAND!!!\n",15);
  continue;
 }
 for(i=cstart;i<99;i++)
 {
  if(buff[i+1]==' '||buff[i+1]=='\t'||buff[i+1]=='\n')
  {
   cend=i;
   break;
  } 
 }
 char rlcmd[101];
 char cmdname[100];
 int br=0;
 for(i=cstart;i=cend;i++)
 {
  rlcmd[br]=buff[i];
  cmdname[br]=buff[i];
  br++;
 }
 rlcmd[br]='\0';
 if(buff[cend]=='&') bg=1;
 if((a=fork()))
 {
  if(bg==0) wait(&stat);
  else printf();
 }
 else
 {
  execlp(cmdname,rlcmd);
 }
}
return 0;
}
