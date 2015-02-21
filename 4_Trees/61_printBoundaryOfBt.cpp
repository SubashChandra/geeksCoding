//given a bt, print boundary of tree in anti clock wise direction
//O(n) time
//O(logn) space



#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

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

Bstnodeptr max(Bstnodeptr root)
{
	if(root->right==NULL)
		return root;

	//else go recursive
	return max(root->right); 
}


//delete node in the bst
Bstnodeptr deletenode(Bstnodeptr root, int data)
{
	Bstnodeptr temp;
	if(root==NULL)
	{
		printf("element not found\n");
	}

	else if(data<root->data) //go recursive on left child
		root->left=deletenode(root->left,data);

	else if(data>root->data) //right
		root->right=deletenode(root->right,data);

	else //data  foudn
	{
		if(root->left !=NULL && root->right !=NULL) //if node has two children
		{
			temp = max(root->left); //find max in the left child, copy it to root nd delete that node
			root->data = temp->data;
			root->left = deletenode(root->left,root->data);
		}
		else //only one child
		{
			temp=root;
			if(root->left==NULL)
				root=root->right;
			else if(root->right==NULL)
				root=root->left;
			free(temp);
		}
	}
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


//preorder traversal of a tree
void preorder(Bstnodeptr root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

//postorder traversal of a tree
void postorder(Bstnodeptr root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}




//print leaves  form left to right
void printLeaves(Bstnodeptr root)
{
	if(root)
	{
		printLeaves(root->left);
		if(root->left==NULL && root->right==NULL)
			printf("%d ",root->data);

		printLeaves(root->right);
	}
}


//prinyt right bottom up
void printRight(Bstnodeptr root)
{
	if(root)
	{
		if(root->right)
		{
			printRight(root->right);
			printf("%d ",root->data);
		}
		else if(root->left)
		{
			printRight(root->right);
			printf("%d ",root->data);
		}
	}
}

void printLeft(Bstnodeptr root)
{
	if(root)
	{
		if(root->left)
		{
			printf("%d ",root->data);
			printLeft(root->left);
		}
		else if(root->right)
		{
			printf("%d ",root->data);
			printLeft(root->right);
		}
	}
}

void printBoundary(Bstnodeptr root)
{
	if(root==NULL)
		return;

	printLeft(root);
	printLeaves(root);
	if(root->right) //root should be printed only once~
		printRight(root->right);
	printf("\n");
}


int main()
{
	Bstnodeptr root = NULL;

	int data;	
	printf("enter data or -1 to break ");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;

		root=insert(root,data);
	}
	printf("preorder: ");
	preorder(root);
	printf("\n");

	printBoundary(root);
	return 0;
}
