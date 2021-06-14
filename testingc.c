#include<stdio.h>
int main()
{
	char something[50];
	char other[50];
	scanf("%50[^\n]s",something);
	fgets(other,50,stdin);
	printf("Returning: %s",something);
	printf("Returning: %s",other);
	return 0;
}
