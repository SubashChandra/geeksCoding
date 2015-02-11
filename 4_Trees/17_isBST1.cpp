//given a tree check if its binary or not
//each node is visited multiple times
//O(2^n) time
//O(n) space

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

struct bstnode
{
	struct bstnode *left;
	int data;
	struct bstnode *right;
};

typedef struct bstnode Bstnode;
typedef Bstnode *Bstnodeptr;


Bstnodeptr newnode(int data)
{
	Bstnodeptr temp=(Bstnodeptr)malloc(sizeof(Bstnode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

//levelorder insert using queue
void insert(Bstnodeptr *root, int data)
{
	if(*root==NULL)
	{
		*root=newnode(data);
		return;
	}

	Bstnodeptr temp = *root;
	queue<Bstnodeptr> q1;

	q1.push(temp);
	while(q1.size()!=0)
	{
		temp=q1.front();
		q1.pop();

		if(temp->left==NULL) //if left empty, insrt here
		{
			temp->left=newnode(data);
			return;
		}
		else
			q1.push(temp->left); //else push it to queue

		if(temp->right==NULL) //insert here
		{
			temp->right=newnode(data);
			return;
		}
		else //or push it to queue
			q1.push(temp->right);
	}

}

void preorder(Bstnodeptr root)
{
	if(root==NULL)
		return;

	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}


int getMax(Bstnodeptr root)
{
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root->data;
}


int getMin(Bstnodeptr root)
{

	while(root->left!=NULL)
		root=root->left;
	return root->data;
}


int isBST(Bstnodeptr root)
{
	if(root==NULL) 
		return 1;

	if(root->left && getMax(root->left)>root->data)
		return 0;

	if(root->right && getMin(root->right)<root->data)
		return 0;

	if(!isBST(root->left) || !isBST(root->right))
		return 0;

	return 1;

}


int main()
{
	Bstnodeptr root = NULL;

	int data;

	printf("tree: ");
	while(1)
	{
		printf("enter data or -1 to exit: ");
		scanf("%d",&data);
		if(data==-1)
			break;
		insert(&root,data);
	}
	printf("preorder : ");
	preorder(root);
	printf("\n");

	printf("%s\n",isBST(root)?"yes":"no");

	return 0;
}
