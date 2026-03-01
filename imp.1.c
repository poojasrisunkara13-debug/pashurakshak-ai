#include<stdio.h>
#include<stdbool.h>
int main()
{
	bool b=true;
	char c='A';
	float d=245.3;
	int i=3650;
	short s=78;
	printf("bool+char is char: %c\n",b+c);
	printf("int*short is int: %d\n",i*s);
	printf("float*char is float: %f\n",d*c);
	c=c+b;       //bool promoted to char 
	d=d+c;      //char promoted by float
	b=-d;      //float demoted by bool
	printf("\n after exceution__\n");
	printf("char + true: %c\n",c);
	printf("float + char: %f\n",d);
	printf("bool = -float: %f\n",b);
} 
