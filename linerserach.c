#include<stdio.h>
void main()
{ 
int num;
int i,key;
printf("enter no.of elememts u would like to take:");
scanf("%d",&num);
int arr[num];
printf("\n enter all the elements of your choice:");
for(i=0;i<num;i++);
{
	scanf("%d",&arr[i]);
}
printf("\n enter the key element that you would like to search:");
scanf("%d",&key);
for(i=0;i<num;i++)
{
	if(key==arr[i])
	printf("we got elements at index %d",i+1);
}
}
