#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
 if(fork())
 {
 printf("Rod chaka 32 \n");
 wait(32);
 printf("Rod svurshva \n");
 }
 else{printf("Dete izl. s 0 \n");
 exit(0);}
 return 0;
}
