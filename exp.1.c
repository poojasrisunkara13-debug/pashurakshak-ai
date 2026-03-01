#include<stdio.h>
int main()
{
	char achar='\0';
	int intnum1=100;
	int intnum2=45;
	double fltnum1=100.0;
	double fltnum2=45.0;
	double fltnum3;
	printf("achar num:%3d\n",achar);
	printf("intnum1 contains: %3d\n",intnum1);
	printf("intnum2 contains: %3d\n",intnum2);
	printf("fltnum1 contains: %6.2\n",fltnum1);
	printf("fltnum2 contains: %6.2\n",fltnum2);
	fltnum3=(double)(intnum1/intnum2);
	printf("\n(double)(intnum1/int2);%6.2f\n",fltnum3);
	fltnum3=(double)intnum1/intnum2;
	printf("(double)intnum1/intnum2:%6.2f\n",fltnum3);
	achar=(char)(fltnum1/fltnum2);
	printf("(char)(fltnum1/fltnum2):%3d\n",achar);
}
