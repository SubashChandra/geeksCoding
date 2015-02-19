//avl delete
//balance bst using single nd double rotations
//O(logn) time
//O(logn) space


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

struct bstnode
{
	int data;
	int height;
	struct bstnode *left;
	struct bstnode *right;
};

typedef struct bstnode Bstnode;
typedef Bstnode *Bstnodeptr;

int max(int a, int b)
{
	return a>b?a:b;
}


int height(Bstnodeptr root)
{
	if(root)
		return root->height;
	return 0;
}


Bstnodeptr singleRotateRight(Bstnodeptr root)
{
	Bstnodeptr temp = root->left;
	root->left=temp->right;
	temp->right = root;

	root->height = max(height(root->left),height(root->right))+1;
	temp->height = max(height(temp->left),height(temp->right))+1;

	return temp;
}


Bstnodeptr singleRotateLeft(Bstnodeptr root)
{
	Bstnodeptr temp = root->right;
	root->right = temp->left;
	temp->left = root;

	root->height = max(height(root->left),height(root->right))+1;
	temp->height = max(height(temp->left), height(temp->right))+1;

	return temp;
}

Bstnodeptr doubleRotateLeft(Bstnodeptr root)
{
	root->right = singleRotateRight(root->right);
	return singleRotateLeft(root);
}

Bstnodeptr doubleRotateRight(Bstnodeptr root)
{
	root->left=singleRotateLeft(root->left);
	return singleRotateRight(root);
}

Bstnodeptr insert(Bstnodeptr root, int data)
{
	Bstnodeptr newnode;

	if(root==NULL) //if null 
	{
		newnode=(Bstnodeptr)malloc(sizeof(Bstnode));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->height=1;
		root = newnode;
	}

	else if(root->data == data)
		printf("duplicate\n");

	else if(data <root->data) //go recursive to the left subtree
	{
		root->left=insert(root->left,data);
		if(height(root->left)-height(root->right) ==2)
		{
			if(data < root->left->data)
				root=singleRotateRight(root);
			else
				root=doubleRotateRight(root);
		}
	}

	else if(data > root->data)
	{
		root->right=insert(root->right,data);
		if(height(root->right)-height(root->left)==2)
		{
			if(data>root->right->data)
				root=singleRotateLeft(root);
			else
				root=doubleRotateLeft(root);
		}
	}
	root->height = max(height(root->left),height(root->right))+1; 

	return root;
}


Bstnodeptr maxNode(Bstnodeptr root)
{
	while(root->right)
		root=root->right;
	return root;
}

Bstnodeptr deleteNode(Bstnodeptr root, int data)
{
	if(root==NULL)
		return NULL;
	Bstnodeptr temp;
	if(root->data==data) //if found
	{
		//if two children
		if(root->left!=NULL && root->right!=NULL)
		{
			temp=maxNode(root->left);
			root->data=temp->data;
			root->left=deleteNode(root->left,temp->data);
		}
		else //if one or no children
		{
			temp=root;
			if(root->left==NULL)
				root=root->right;
			else if(root->right==NULL)
				root=root->left;

			free(temp);
		}
	}

	else if(data < root->data)
	{
		root->left = deleteNode(root->left, data);
		if(height(root->right)-height(root->left)==2) //check for balance nd do app rotations
		{
			if(root->right->right) //singleRotation
				root=singleRotateLeft(root);
			else //doubleRotation
				root=doubleRotateLeft(root);
		}
	}

	else if(data > root->data)
	{
		root->right=deleteNode(root->right, data);
		if(height(root->left)-height(root->right) == 2) //check nd do app rotations
		{
			if(root->left->left) //single rotation
				root=singleRotateRight(root);
			else 
				root=doubleRotateRight(root);
		}
	}

	if(root)
		root->height=max(height(root->left),height(root->right))+1; //update height
	return root;
}

Bstnodeptr max(Bstnodeptr root)
{
	if(root->right==NULL)
		return root;

	//else go recursive
	return max(root->right); 
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
		printf("preorder: ");
		preorder(root);
		printf("\n");
	}
	printf("*****************\n");
	printf("enter data to deleteor -1 to break ");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;

		root=deleteNode(root,data);
		printf("preorder: ");
		preorder(root);
		printf("\n");
	}
	return 0;
}
