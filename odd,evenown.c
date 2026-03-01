#include<stdio.h>
int main()
{
	int i;
	printf("\neven nos btw 1 to 100:\n");
	for(i=1;i<=100;i++)
	{
		if(i%2==0)
		{
			printf("%d\n",i);
		}
		}
	printf("\nodd numbers 1 to 100:\n");
	for(i=1;i<=100;i++)
	{
		if(i%2!=0)
		{
			printf("%d\n",i);
		}
	}
	}
