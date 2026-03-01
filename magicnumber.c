#include<stdio.h>
int main()
{
	int n,temp,rev=0,digit,sum_of_digits=0;
	printf("enter a number:\n");
	scanf("%d",&n);
	temp=n;
	while(temp>0)
	{
		sum_of_digits=sum_of_digits+temp%10;
		temp=temp/10;
	}
	temp=sum_of_digits;
	printf("\n the sum of the digits=%d",temp);
	while(temp>0)
    {
    	rev=rev*10+temp%10;
    	temp=temp/10;
	}
	printf("\n the reverse of the digit=%d",rev);
	printf("\n the product of %d*%d=%d",sum_of_digits,rev*rev,sum_of_digits);
    if (rev*sum_of_digits==n)	
    printf("\n%d is a magic nuumber",n);
    else 
    printf("\n %d is not a magic number",n);
}
