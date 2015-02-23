//given a binaryTree convert it into a DLL;
//do inorder tarversal, nd update left by keeping track of prev node
//go tp right most node, traverse back nd update right by keep tracking of prev node

//O(n)
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


void updateLeft(Bstnodeptr root,Bstnodeptr *pre)
{
	if(root)
	{
		updateLeft(root->left,pre);
		root->left=*pre; //set left to last visited node
		*pre=root; //update pre
		updateLeft(root->right,pre);
	}
}
	

void updateRight(Bstnodeptr root)
{
	Bstnodeptr pre=NULL;

	while(root->right) //go to right most node
		root=root->right;

	while(root) //traverse back using left nd update right using pre
	{
		root->right=pre;
		pre=root; //update pre
		root=root->left;
	}
}

Bstnodeptr convertToDll(Bstnodeptr root)
{
	if(root==NULL)
		return NULL;

	Bstnodeptr pre=NULL;

	updateLeft(root,&pre); //update left
	updateRight(root); //update right

	while(root->left) //have to return left most node
		root=root->left;

	return root;
}

void printDll(Bstnodeptr root)
{
	if(root==NULL)
		return;
	Bstnodeptr pre=NULL; //to priny in reverse

	printf("dll: ");
	while(root)
	{
		printf("%d ",root->data);
		pre=root;
		root=root->right;
	}
	printf("NULL\n\ndll in reverse: ");

	while(pre)
	{
		printf("%d ",pre->data);
		pre=pre->left;
	}
	printf("NULL\n");
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

	root=convertToDll(root);

	printDll(root);
	return 0;
}
