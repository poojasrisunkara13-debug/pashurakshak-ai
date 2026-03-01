/* c program to print simple intrest */
#include<stdio.h>
int main()
{
	int p,t;
	float r,si;
	printf ("enter principal amount & time & rate of intrest");
	scanf("%d,%d,%f",&p,&t,&r);
	si=(p*t*r)/100;
	printf("enter simple intrest is:%f",si);
}
