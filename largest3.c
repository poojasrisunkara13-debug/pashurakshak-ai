#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter 3 values");
	scanf("%d %d %d",&a,&b,&c);
	if ((a>b)&&(a>c))
	printf("a is largest %d",a);
	else if ((b>a)&&(b>c))
	printf("b is largest %d",b);
	else if ((c>a)&&(c>b))
	printf("c");
}
