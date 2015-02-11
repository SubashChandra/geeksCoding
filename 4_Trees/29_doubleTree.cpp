//given a binary tree, insert duplicate node as the left child of the original node
//do it in a postorder traversal

//O(n) time

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>


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



Bstnodeptr newnode(int data)
{
	Bstnodeptr temp = (Bstnodeptr)malloc(sizeof(Bstnode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


void levelOrder(Bstnodeptr root)
{
	printf("levelorder: ");
	if(root==NULL)
		return;

	queue<Bstnodeptr> q1;
	q1.push(root);

	while(q1.size()!=0)
	{
		root=q1.front();
		q1.pop();
		printf("%d ",root->data);

		if(root->left)
			q1.push(root->left);

		if(root->right)
			q1.push(root->right);
	}
	printf("\n");
}





//create a double tree
void doubleTree(Bstnodeptr root)
{
	if(root==NULL)
		return;

	doubleTree(root->left);
	doubleTree(root->right);

	Bstnodeptr oldLeft = root->left;
	root->left=newnode(root->data);
	root->left->left=oldLeft;
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

	doubleTree(root);
	levelOrder(root);

	printf("preorder: ");
	preorder(root);
	printf("\n");

	return 0;
}
