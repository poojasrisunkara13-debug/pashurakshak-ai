#include<stdio.h>
int main()
{
int i,c=0,n;
printf("Enter any number:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
if(n%i==0)
c++;
}
if(c==2)
printf("%d is prime.\n",n);
else
printf("%d is not a prime.\n",n);
}
