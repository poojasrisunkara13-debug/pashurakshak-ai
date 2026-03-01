#include<stdio.h>
#include<stdlib.h>
Struct CLL
{
	int data;
	struct CLL*link;
};
Struct CLL*start=NULL
void createlist(int n);
int Countnode();
void insert_at_beg();
void inset_at_end();
void insert_at_pos();
void delete_at_beg();
void delete_at_end();
void delet_at_pos();
void traverse();
void rev_traverse(struct CLL*start);
struct CLL*getnode()
{
	int value;
	Struct CLL*newnode=(struct CLL*)malloc(sizeof(structCLL))
	printf("ENTER DATA:");
	scanf("%d",value);
	newnode->data=value;
	newnode->link=NULL;
	return newnode;
}
void Createlist(int n)
{
	int i;
	struct CLL*newnode,*temp;
	for(i=0;i<n;i++)
	{
		newnode=getnode();
		if (start==NULL);
		{
			start=newnode;
			temp=newnode;
			newnode->link=start;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;
			temp->link=start;
		}
    }
}
void insert_at_beg()
{
	struct CLL*newnode*temp;
	newnode=getnode();
	if(start==NULL)
	{
		start=newnode;
		newnode->link=start;
	}
	else
	{
		for(temp=start;temp->link!=start;temp=temp->link);
		temp->link=newnode;
		newnode->link=start
		start=newnode;
	}
}
void insert_at_end()
{
	struct CLL*newnode,*temp;
	newnode=getnode();
	if(start==NULL)
	{
		start=newnode;
		newnode->link=start;
	}
	else
	{
		for(temp=start;temp->link!=start;temp=temp->link);
		temp->link=newnode;
		newnode->link=start
	}
}
int  countnode()
{
	int count=0;
	struct CLL*temp=start;
	if(start==NULL)
	return count;
	temp start;
	do
	{
		count++
		temp=temp->link;
	}while(temp!=start);
	return count;
}
void insert_at_pos()
{
	struct CLL*newnode,*temp;
	int pos,i;
	newnode=getnode();
	printf("ENTER POSITION:");
	scanf("%d",&pos);
	int no_of_node=countnode();
	if(pos<1||pos>no_of_nodes+1)
	{
		printf("invalid position\n");
		return;
	}
	if(pos==1)
	{
		insert_at_beg();
		return;
	}
	temp=start;
	for(i=1;i<pos-1;i++)
	temp=temp->link;
	newnode->link=temp->link;
	temp->link=newnode;
}
void delete_at_beg();
{
	struct CLL*temp,*last
	if(start==NULL)
	{
		printf("no nodes are existing\n");
		return;
	}
	if(start->link==start)
	{
		printf("deleted nodes data:\n",start->data);
		free(start);
		start=NULL;
	}
	else
	{

	temp = start;
    for(last = start;last->link != start;last = last->link);
    start = start->link;
    last->link = start;
    printf("Deleted node data: %d\n", temp->data);
    free(temp);
    }
}
void delete_at_pos()
{
   struct CLL *temp, *prev;
   int pos, i, no_of_nodes;
   if (start == NULL) // case 1: list is empty
   {
    printf("List is empty.\n");
    return;
   }
   printf("Enter position of node to delete: ");
   scanf("%d", &pos);
   no_of_nodes = countnode();
   if (pos < 1 || pos > no_of_nodes)
   {
    printf("Invalid position.\n");
    return;
   }

