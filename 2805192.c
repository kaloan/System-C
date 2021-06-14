#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv)
{
 int i=0;
 if(fork())
 {
  i++;
 }
 else
 {
  i--;
 }
 exit(0);
 printf("i: %d \n", i);
 return 0;
}
