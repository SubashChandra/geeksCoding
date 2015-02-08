//given two trees check if they are the same


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


int compare(Bstnodeptr root1, Bstnodeptr root2)
{
	if(root1==NULL && root2==NULL)
		return 1;

	else if(root1!=NULL && root2!=NULL) //if not null, compare data, left nd right 
		return root1->data==root2->data && compare(root1->left,root2->left) && compare(root1->right,root2->right);

	return 0;
}

int main()
{
	Bstnodeptr root1 = NULL;
	Bstnodeptr root2 = NULL;

	int data;

	printf("tree1: ");
	printf("enter data or -1 to exit: ");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;
		insert(&root1,data);
	}
	printf("preorder : ");
	preorder(root1);
	printf("\n");

	printf("tree2: ");
	printf("enter data or -1 to exit: ");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;
		insert(&root2,data);
	}
	printf("preorder : ");
	preorder(root2);
	printf("\n");

	printf("%s\n",compare(root1,root2)?"same":"different");

	return 0;
}
