//check if a given binary tree is a sum tree
//checking if node data == twice the sum of its children, post order way

//O(n) time

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

int isLeaf(Bstnodeptr root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return 0;
}


//check if a tree is sumtree or not
int isSumTree(Bstnodeptr root)
{
	if(root==NULL || isLeaf(root))
		return 1;

	int lSum,rSum;
	if(root->left==NULL)
		lSum=0;
	else if(isLeaf(root->left)) //if leaf, lsum will be of only one node
		lSum=root->left->data;
	else //willl be of a subtree of more than one node
		lSum=2*(root->left->data);

	if(root->right==NULL)
		rSum=0;
	else if(isLeaf(root->right))
		rSum=root->right->data;
	else
		rSum=2*(root->right->data);

	return lSum+rSum==root->data && isSumTree(root->left) && isSumTree(root->right);
}



int main()
{
	Bstnodeptr root = NULL;

	int data;

	printf("tree: ");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;
		insert(&root,data);
	}
	printf("preorder : ");
	preorder(root);
	printf("\n");
	
	printf("%s\n",isSumTree(root)?"yes":"no");

	return 0;
}
