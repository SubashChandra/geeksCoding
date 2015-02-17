//insert elements into a binary search tree nd print them

//time: O(log n) time


#include<stdio.h>
#include<stdlib.h>

struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

typedef struct bstnode Bstnode;
typedef Bstnode *Bstnodeptr;


Bstnodeptr insert(Bstnodeptr root, int data)
{
	Bstnodeptr newnode;

	if(root==NULL) //if null 
	{
		newnode=(Bstnodeptr)malloc(sizeof(Bstnode));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		root = newnode;
	}

	else if(root->data == data)
		printf("duplicate\n");

	else if(data <root->data) //go recursive to the left subtree
		root->left=insert(root->left,data);

	else //go recursive to teh right subtree
		root->right=insert(root->right,data);

	return root;
}

//inorder traversal of a tree
void inorder(Bstnodeptr root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main()
{
	Bstnodeptr root = NULL;

	int data;

	while(1)
	{
		printf("enter data or -1 to end: \n");
		scanf("%d",&data);
		if(data==-1)
			break;
		root = insert(root,data);
		printf("inorder:  ");
		inorder(root);
		printf("\n");
	}

	return 1;
}
