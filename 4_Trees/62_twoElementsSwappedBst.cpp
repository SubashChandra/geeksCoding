//given a bst with two swapped elements, correct it
//using inorder traversal, nd using 4 pointers

//O(n) time
//O(logn) space

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>

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



//if swapped elements are adjacent, secomd wll be NULL, then swap first nd temp
void util(Bstnodeptr root, Bstnodeptr *first, Bstnodeptr *temp, Bstnodeptr *second, Bstnodeptr *pre)
{
	if(root)
	{
		util(root->left,first,temp,second,pre);


		if(*pre && root->data<(*pre)->data)
		{
			if(*first==NULL) //if first occurrence
			{
				*first=*pre;
				*temp=root;
			}
			else //second occurrence
				*second=root;
		}
		*pre=root;

		util(root->right,first,temp,second,pre);
	}
}

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void correctBst(Bstnodeptr root)
{
	if(root==NULL)
		return;

	Bstnodeptr pre, first,second,temp;
	pre=first=second=temp=NULL;

	util(root,&first,&temp,&second,&pre);

	if(first && second) //not adjacent
		swap(&(first->data),&(second->data));
	else if(first && temp) //swapped elements are adjacent
		swap(&(first->data),&(temp->data));
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

	correctBst(root);
	
	printf("preorder after correcting swap : ");
	preorder(root);
	printf("\n");


	return 0;
}
