
#include<stdio.h>
int main()
{
	int a[10];
	int i;
	for(i=0;i<10;i++)
	{
	scanf("%d",&a[i]);
	}
	int br=0;
	printf("The negatives are: ");	
	for(i=0;i<10;i++)
	{
		if(a[i]<0)
		{
			printf("%d, ",a[i]);
			br++;
		}
	}
	printf("\n Their number is: %d",br);
	return 0;
}
