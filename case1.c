#include<stdio.h>
int main()
{
	char ch;
	printf("\n enter any charactr:");
	scanf("%c",&ch);
	switch(ch)
	{
		case'a':
			printf("\n char entered is vowel.");
			break;
		case'e':
			printf("\n char entered is vowel.");
			break;
		case'i':
			printf("\n char entered is vowel.");
			break;
		case'o':
			printf("\n char entered is vowel.");
			break;
		case'u':
			printf("\n char entered is vowel.");
			break;
		default:
			printf("\n char entered is not a vowel.");
	}
}
