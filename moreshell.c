#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
char cmd[100];
char* args[10];
main(int argc, char* argv[]){
char buff[1];
int stat;
int pid;
int i;
while(1)
{
 int br=0;
 int j=0;
 int changeIOpos=-1;
 args[0]=&cmd[0];
 write(1,"MYPROMPT@ME>",12);
 while(read(0,buff,1)&&buff[0]!='\n')
 {
  if(buff[0]=='>'||buff[0]=='<') changeIOpos=j;
  if(buff[0]!=' '&&buff[0]!='\t')  cmd[br++]=buff[0];
  else if(cmd[br-1]!='\0')
  {
   cmd[br++]='\0';
   args[++j]=&cmd[br];
  } 
 }
 //args[j+1]=NULL;
 for(i=0;i<10;i++)
 {
  printf("Part %d: %s\n",i,args[i]);
 }
 //printf("CMD is %s\n",cmd);
 if(strcmp("exit",cmd)==0) exit(0);
 //if(cmd[0]='\0') continue;
 pid=fork();

 if(pid>0)
 {
  if(cmd[br-1]=='&') waitpid(-1,&stat,WNOHANG);
  else wait(&stat);
  //write(1,"DONE\n",5);
  if(stat==0) printf("PROCESS WITH PID: %d, CMD: %s\n",pid,cmd);
  else if(strcmp("\0",cmd)!=0) printf("ERROR IN COMMAND:%s\n",cmd);
  memset(cmd,'\0',100);
  for(i=0;i<10;i++)
  {
   args[i]=NULL;
  }
 }

 else
 {
  /*char pop[1];
  pop[0]=cmd[br-1];
  write(1,pop,1);*/
  //if(cmd[br-1]=='&') cmd[br-1]='\0';
  if(changeIOpos!=-1){
  if(strcmp(args[changeIOpos],">")==0)
  {
  args[changeIOpos]=NULL;
  close(1);
  open(args[changeIOpos+1],O_CREAT|O_WRONLY,0777);
  }
  else if(strcmp(args[changeIOpos],"<")==0)
  {
  args[changeIOpos]=NULL;
  close(0);
  open(args[changeIOpos+1],O_RDONLY);
  }
  }
  if(strcmp(args[j],"&")==0) args[j]=0;
  if(execvp(args[0],args)<0) exit(1);
 }

}
}
