//given inorder nd preorder, build a tree


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

struct bstnode
{
	char data;
	struct bstnode *left;
	struct bstnode *right;
};

typedef struct bstnode Bstnode;
typedef Bstnode *Bstnodeptr;



Bstnodeptr newTreeNode(char data)
{
	Bstnodeptr temp = (Bstnodeptr)malloc(sizeof(Bstnode));
	temp->data = data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

int search(char in[], int strt, int end, char data)
{
	int i;
	for(i=strt;i<=end;i++)
	{
		if(in[i]==data)
			return i;
	}
}


//build inorder from inorder nd preorder
Bstnodeptr build(char in[], char pre[], int inStrt, int inEnd)
{
	static int preIndex=0;


	if(inStrt>inEnd)
		return NULL;
	
	Bstnodeptr newnode = newTreeNode(pre[preIndex++]); 
	
	//if tis node has no children, return 
	if(inStrt==inEnd)
		return newnode;

	//find the index of the node in the inorder traversal
	int inIndex = search(in,inStrt, inEnd, newnode->data);
	
	//using inorder idex, construct left nd right subtrees for newnode
	newnode->left = build(in,pre,inStrt, inIndex-1);
	newnode->right = build(in, pre, inIndex+1, inEnd);

	return newnode;
}
	

void levelOrder(Bstnodeptr root)
{
	if(root==NULL)
		return;

	printf("levelOrder: ");
	queue<Bstnodeptr>q1;

	q1.push(root);

	while(q1.size()!=0)
	{
		root=q1.front();
		q1.pop();

		printf("%c ",root->data);
		if(root->left)
			q1.push(root->left);
		if(root->right)
			q1.push(root->right);
	}
	printf("\n");
}


int main()
{
	int n;
	printf("enter no of nodes: ");
	scanf("%d",&n);
	char in[n];
	char pre[n];

	scanf("%s %s",in,pre);

	Bstnodeptr root=build(in,pre,0,n-1);

	levelOrder(root);

	return 0;
}
