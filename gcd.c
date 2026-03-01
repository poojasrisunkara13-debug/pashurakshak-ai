#include <stdio.h>
int main()
{
int a,b;
printf("Enter any two integers:");
scanf("%d%d",&a,&b);
printf("The gcd of %d and %d is:%d",a,b,gcd(a,b));
}
int gcd(int a, int b) {
if (b != 0)
return gcd(b, a%b);
else
return a;
}
