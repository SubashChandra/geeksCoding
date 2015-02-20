//given a binary tree, conver it into bst keeping structure intact
//using vector, sort nd inorder traversal
//O(n) time
//O(n) space


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

//poplate vector with inorder of bt
void getElements(Bstnodeptr root, vector<int> *v)
{
	if(root)
	{
		getElements(root->left,v);
		(*v).push_back(root->data);
		getElements(root->right,v);
	}
}

//build bst
void putElements(Bstnodeptr root, vector<int> v, int *index)
{
	if(root)
	{
		putElements(root->left,v,index);
		root->data=v[*index];
		(*index)++;
		putElements(root->right,v,index);
	}
}



void convertToBst(Bstnodeptr root)
{
	vector<int> v;
	getElements(root,&v); //get elements of tree
	int i;

	sort(v.begin(), v.end()); //sort them

	int index=0;
	putElements(root,v,&index); //now put them back but in sorted order 
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
	printf("binary tree preorder : ");
	preorder(root);
	printf("\n");

	convertToBst(root);
	
	printf("bst preorder: ");
	preorder(root);
	printf("\n");


	return 0;
}
