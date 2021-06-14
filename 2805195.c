#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
 int a=execl("/bin/date","date",0);
 return 0;
}
