//given a bt, find the vertical sum along each columns
//inorder traversal
//using map to keep track of sum nd one variable to track each column
//O(n) time
//O(n) space


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>

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



void verticalSumUtil(Bstnodeptr root, map<int,int> *m1,int level)
{
	if(root==NULL)
		return;

	//left recursive
	verticalSumUtil(root->left,m1,level-1);

	//handle current node
	map<int,int>::iterator i;
	i=(*m1).find(level);
	if(i==(*m1).end()) //if not present, insert
		(*m1).insert(pair<int,int>(level,root->data));
	else //if already present
		i->second+=root->data;

	//right recursive
	verticalSumUtil(root->right,m1,level+1);	
}



//usse a helper method to do inorder traversal nd add node data to appropriate keys
void printVerticalSum(Bstnodeptr root)
{
	if(root==NULL)
		return;
	map<int,int> m1;
	verticalSumUtil(root,&m1,0);

	map<int,int>::iterator i;
	for(i=m1.begin();i!=m1.end();i++)
	{
		printf("%2d -> %d **\n",i->first,i->second);
	}
}

int main()
{
	Bstnodeptr root = NULL;

	int data;	
	printf("enter data or -1 to break ");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;

		root=insert(root,data);
	}
	printf("preorder: ");
	preorder(root);
	printf("\n");

	printVerticalSum(root);

	return 0;
}
