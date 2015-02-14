//given a binary tree, print level of a given element
//O(n) time
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

//get level ofa given elemnt
int getLevel(Bstnodeptr root, int data, int level)
{
	if(root==NULL)
		return -1;

	if(root->data==data)
		return level;

	//else go recursive
	int ans;
	ans=getLevel(root->left, data, level+1);
	if(ans!=-1) //if found
		return ans;

	else
		return getLevel(root->right,data,level+1);

} //return 0 if data not found


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

	int level=1;
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;
		level=1;
		printf("level is %d\n",getLevel(root,data,level));

	}

	return 0;
}
