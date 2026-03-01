#include<stdio.h>
int main(int argc,char*argv[])
{
	int i;
	printf("\n program name:%s",argv[0]);
	if(argc<2){
		printf("\n\n no argument passed through command line.\n");
	}else
	printf("\n argument supplied:");
	for(i=0;i<argc;i++)
	{
		printf("%d\t",argv[i]);
	}
	int sum=0;
	for (i=1;i<argc;i++){
		sum=sum+argv[i];
	}
	printf("%s\t",sum);
}
