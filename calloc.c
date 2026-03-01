#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,*ptr,sum=0;
	printf("enter number of elements:");
	scanf("%d",&n);
	ptr=(int*)calloc(n,sizeof(int));
	if(ptr==NULL){
    printf("error! memory not allocated");
    exit(0);}
	printf("enter elements:");
	for (i=0;i<n;i++){
	scanf("%d",ptr+i);
	sum+=*(ptr+i);
	}
	printf("sum=%d",sum);
	free(ptr);
}
