//given a tree make sure it satisfies choldren sum, node data can only be incremented
//first go recursive, left nd right nd check for node

//O(n^2) time

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


//increment sub tree by diff, either left or right recursively
void increment(Bstnodeptr root, int diff)
{
	if(root->left)
	{
		root->left->data+=diff;
		increment(root->left,diff);
	}
	else if(root->right)
	{
		root->right->data+=diff;
		increment(root->right,diff);
	}
}



//children sum property
void checkNdSatisfy(Bstnodeptr root)
{
	int l,r;
	int diff;
	l=0;
	r=0;

	if(root==NULL || (root->left==NULL && root->right==NULL))
		return;

	else
	{
		//go recursive
		checkNdSatisfy(root->left);
		checkNdSatisfy(root->right);

		if(root->left)
			l=root->left->data;
		if(root->right)
			r=root->right->data;

		//now calc diff between (left+rigth - node)
		diff=(l+r)-root->data;

		//if diff is +ve, add it to the node value
		if(diff>=0)
			root->data+=diff;

		//else add mod of it recursively to left or right child
		else
			increment(root,-diff);
	}
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

	checkNdSatisfy(root);

	printf("preorder after : ");
	preorder(root);
	printf("\n");

	return 0;
}
