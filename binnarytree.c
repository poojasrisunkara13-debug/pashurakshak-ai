//binary tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*left;
	int data;
	struct node*right;
};
struct node*create()
{
	int x;
	struct node*newnode;
	printf("\n enter data or -1 to end the node:");
	scanf("%d",&x);
	if(x==-1)
	return NULL;
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node*));
		newnode->data=x;
		printf("\n enter left child of %d:",x);
		newnode->left=create();
		printf("\n enter the right child of %d:",x);
		newnode->right=create();
		return newnode;
	}
}
void preorder(struct node*t)
{
	if(t!=NULL)
	{
		printf("%d",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void postorder(struct node*t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d",t->data);
	}
}
void inorder(struct node*t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d",t->data);
		inorder(t->right);
	}
}
int main()
{
	struct node*root=NULL;
	root=create();
	printf("\n preorder traversal of a tree:");
	preorder(root);
	printf("\n postorder traversal of a tree:");
	postorder(root);
	printf("\n inorder traversal of a tree:");
	inorder(root);
	return 0;	
}
