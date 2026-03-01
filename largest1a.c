//largest of 2 numbers
#include<stdio.h>
int main()
{
	int num1,num2;
	printf("enter 2 numbers:");
	scanf("%d%d",num1,num2);
	if (num1>num2)
	printf("largest number:%d\n",num1);
	else
	printf("largest number:%d\n",num2);
	return 0;
}
