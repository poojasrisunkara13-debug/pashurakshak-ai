#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
int main()
{
	struct node*head=malloc(sizeof(struct node));
	head->data=45;
	head->link=NULL;
	
	struct node*current=malloc(sizeof(struct node));
	current->data=97;
	current->link=NULL;
	
	struct node*current2=malloc(sizeof(struct node));
	current2->data=113;
	current2->link=NULL;
	printf("%d\n",head->data);
	printf("%d\n",current->data);
	printf("%d\n",current2->data);
}
