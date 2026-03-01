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
	else if (avg<50)
	printf("gradeF");
	else if (avg>=50&&avg<60)
	printf("gradeD");
	else if (avg>=60&&avg<70)
	printf("gradeC");
	else if (avg>=70&&avg<80)
	printf("gradeB");
	else if (avg>=80&&avg<90)
	printf("gradeA");
	else 
	printf("gradeA+");	
}
