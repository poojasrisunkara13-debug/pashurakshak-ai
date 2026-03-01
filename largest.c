#include<stdio.h>
int main()
{
	int a,b;
	printf("enter 2 values:");
	scanf("%d %d",&a,&b);
	if (a>b)
	printf("%d is largest",a);
	else if (b>a)
	printf("%d is largest",b);
}
