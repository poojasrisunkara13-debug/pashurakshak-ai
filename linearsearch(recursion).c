//linear serach using recursion
#include<stdio.h>
int linearsearh(int arr[],int size,int key)
{
	//if the size of array is zero ,return-1
	if(size==0)
	{
		return-1;
	}
	if(arr[size-1]==key){
		return size-1;
	}
	return linearsearch(arr,size-1,key);
}
int main()
{
	int arr[]={5,15,6,9,4};
	int key=4;
	int index
	=linearsearch(arr,sizeof(arr/sizeof(int),key);
	if(index==-1){
		printf("key not found in the array \n");
	}
	else{
		printf(" key element %d is found at %d index of the givien array\n",key index);
	}
}
