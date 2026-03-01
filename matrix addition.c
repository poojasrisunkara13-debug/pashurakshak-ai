#include<stdio.h>
int main()
{
	int i,k,j,c1,c2,r1,r2;
	int m1[10][10],m2[10][10],m3[10][10];
	printf("\n how many rows and columns in matrix one:");
	scanf("%d%d",&r2,&c2);
	if((r1==r2)&&(c1==c2))
	{
		printf("\n addition is possible:-");
		printf("\n input matrix one:-");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			scanf("%d",&m1[i][j]);
		}
		printf("\n input matrix two:-");
		for(i=0;i<r2;i++)
		{
		 for(j=0;j<c2;j++)
		 scanf("%d",&m2[i][j]);
		}
		/*addition of matrix*/
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			m3[i][j]=m1[i][j]+m2[i][j];
		}
		printf("\n the sum is:-\n");
		for(i=0;i<c1;i++)
		{
			for(j=0;j<r1;j++)
			printf("%5d",m3[i][j]);
			printf("\n");
		}
	}
	else
	printf("\n addition is not possible:-");
}
