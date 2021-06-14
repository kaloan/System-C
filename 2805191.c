#include<stdio.h>
int main(int argc, char* argv[])
{
 if(fork())
 {
	int b=wait(0);
 	printf("V roditeelq: %d, %d, \n",getpid(),getppid());
	printf("b= %d \n",b);
        int a=wait(0);
        printf("a= %d \n",a);
 }
 else 
 {
	printf("V deteto: %d, %d, \n",getpid(),getppid());
 }
 return 0;
}
