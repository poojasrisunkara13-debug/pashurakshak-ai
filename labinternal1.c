//avg marks of 6 subjects
#include<stdio.h>
int main()
{
    float avg;
    int s1,s2,s3,s4,s5,s6;
	printf("enter your marks:");
	scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5,&s6);
	avg=(s1+s2+s3+s4+s5+s6)/6;
	if (avg<0||avg>100)
	printf("wrong enter");
	elseif (avg<50);
	printf("grade E");
	elseif (avg>=50&&avg<=60);
	printf("grade D");
	elseif (avg>=60&&avg<=70);
	printf("grade C");
	elseif (avg>=70&&avg<=80);
	printf("grade B");
	elseif(avg>=80&&avg<=90);
	printf("grade A");
	elseif;
	printf("A+");
}
