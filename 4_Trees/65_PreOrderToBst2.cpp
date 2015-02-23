//given a preorder construct  bst
//use min max nd create node if in range, use a preIndex index pointer
//O(n) time
//O(logn ) space


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

Bstnodeptr newnode(int data)
{
	Bstnodeptr temp = (Bstnodeptr)malloc(sizeof(Bstnode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

Bstnodeptr auxFunc(int pre[],  int *preIndex, int key, int min,int max, int size)
{
	if(*preIndex>=size)
		return NULL;

	Bstnodeptr root=NULL;

	if(key>min && key<max)
	{
		root=newnode(key);
		(*preIndex)++;

		if(*preIndex<size)
		{
			root->left=auxFunc(pre, preIndex,pre[*preIndex],min,key,size);
			root->right=auxFunc(pre,preIndex,pre[*preIndex],key,max,size);
		}
	}
	return root;
}


Bstnodeptr construct(int pre[], int size)
{
	int preIndex=0;

	return auxFunc(pre,&preIndex,pre[0],-10000,10000,size);
}

int main()
{
	Bstnodeptr root = NULL;

	int n;
	scanf("%d",&n);
	int pre[n];
	int i;

	printf("pre: ");
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);


	root=construct(pre,n);
	
	printf("inorder: ");
	inorder(root);
	printf("\n");
	return 0;
}
