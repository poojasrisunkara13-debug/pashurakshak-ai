#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter the values for a,b");
	scanf("%d%d",&a,&b);
	printf("\n the value of c is %d",c=--a+b++);
	printf("\na=%d,\nb=%d",a,b);
}
