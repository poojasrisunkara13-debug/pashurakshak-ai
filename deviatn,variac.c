#include<stdio.h>
#include<math.h>
#define MAXSIZE 10
void main()
{
	float x[MAXSIZE];
	int i,n;
	float avg, variance, std_deviation,sum=0;
	float sum1=0;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter %d real number\n",n);
	for (i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
	for (i=0;i<n;i++);
	{
		sum=sum+x[i];
	}
	avg=sum/(float)n;
	for(i=0;i<n;i++)
	{
		sum=sum+pow((x[i]-avg),2);
	}
	variance=sum1/(float)n;
	std_deviation=sqrt(variance);
	printf("avg of all elements=%2f\n",avg);
	printf("variance of all elements=%2f\n",variance);
	printf("standard deviation=%2f\n",std_deviation);
}


