//multiplication table
#include<stdio.h>
int main()
{
    int i;
    printf("Enter a number:");
    scanf("%d", &i);  
    for(inti=1;i<=10;i++)
	{
        printf("%d x %d = %d\n", num, i, num * i);
    }
    return 0;
}
