//given a tree, do levelorder traversal in spiral form 
//using two stacks

//O(n) time
//O(n) time



#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>

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

//node with the max val
Bstnodeptr max(Bstnodeptr root)
{
	if(root==NULL)
		return NULL;

	while(root->right!=NULL)
		root=root->right;

	return root;
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



void levelOrderSpiral(Bstnodeptr root)
{
	stack<Bstnodeptr> s1;
	stack<Bstnodeptr> s2;
	Bstnodeptr temp;

	s1.push(root);

	while(s1.size()!=0 || s2.size()!=0)
	{
		while(s1.size()!=0)
		{
			temp=s1.top();
			s1.pop();
			printf("%d ",temp->data);
			//push right to left
			if(temp->right)
				s2.push(temp->right);

			if(temp->left)
				s2.push(temp->left);
		}

		while(s2.size()!=0)
		{
			temp=s2.top();
			s2.pop();
			printf("%d ",temp->data);
			//push left to right
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
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
	printf("levelorder spiral: ");
	levelOrderSpiral(root);
	printf("\n");

	return 0;
}
