#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
char cmd[20];
main(int argc, char* argv[]){
char buff[1];
int stat;
int pid;
while(1)
{
 int br=0;
 write(1,"MYPROMPT@ME>",12);
 while(read(0,buff,1)&&buff[0]!='\n')
 {
  if(buff[0]!=' '&&buff[0]!='\t') cmd[br++]=buff[0]; 
 }
 if(strcmp("exit",cmd)==0) exit(0);
 pid=fork();
 if(pid>0)
 {
  if(cmd[br-1]=='&') waitpid(-1,&stat,WNOHANG);
  else wait(&stat);
  //write(1,"DONE\n",5);
  if(stat==0) printf("PROCESS WITH %d, CMD %s",pid,cmd);
  else if(strcmp("\0",cmd)!=0) printf("ERROR IN COMMAND:%s\n",cmd);
  memset(cmd,'\0',20);
 }
 else
 {
  /*char pop[1];
  pop[0]=cmd[br-1];
  write(1,pop,1);*/
  if(cmd[br-1]=='&') cmd[br-1]='\0';
  if(execlp(cmd,cmd,0)<0) exit(1);
 }
}
}
