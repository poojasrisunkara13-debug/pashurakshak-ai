#include<stdio.h>
int main()
{
	float a,b;
	char ch;
	print("1.add,2.sub,3.multiply,4.divide,5.reminder");
	printf("enter your choice");
	scanf("%d",ch);
	printf("enter any 2 values:");
	scanf("%d%d",&a,&b);
	switch(ch)
	{
		case1:
			printf("\n addition is %d",a+b);
			break;
			
	}
}
