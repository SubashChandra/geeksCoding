//given a binary tree, find the maximum sum leaf to root path
//first find the leaf to which sum is max
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


void findMaxLeaf(Bstnodeptr root, int curSum, int *maxSoFar, Bstnodeptr *leaf)
{
	if(root==NULL)
		return;

	curSum+=root->data; //add to curSum nd go recursive

	if(root->left==NULL && root->right==NULL)  //but if leaf, compare with maxSofar nd update leaf
	{
		if(curSum> *maxSoFar)
		{
			*maxSoFar=curSum;
			*leaf=root;
		}
	}

	findMaxLeaf(root->left,curSum, maxSoFar,leaf);
	findMaxLeaf(root->right,curSum,maxSoFar,leaf);
}


//print path from leaf to root
int printPath(Bstnodeptr root, Bstnodeptr leaf)
{
	if(root==NULL)
		return 0;

	if(root==leaf || printPath(root->left,leaf) || printPath(root->right, leaf))
	{
		printf("%d ",root->data);
		return 1;
	}
	return 0;
}


int maxSum(Bstnodeptr root)
{
	if(root==NULL)
		return 0;

	int maxSoFar=0;
	Bstnodeptr maxLeaf;
	
	//find the leaf to which root to leaf sum is max
	findMaxLeaf(root,0,&maxSoFar,&maxLeaf);

	//print path from leafto node
	printPath(root, maxLeaf);

	return maxSoFar;
}


int main()
{
	Bstnodeptr root = NULL;

	int data;

	printf("tree: ");
	printf("enter data or -1 to exit: ");
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

	printf("maxSum is %d\n",maxSum(root));
	return 0;
}
