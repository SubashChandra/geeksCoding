//insert  an element in the splay tree
//isnertion will be at root by splaying

//O(logn) time //first search
//O(1) time //second dearch

//O(logn) space


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

typedef struct bstnode Bstnode;
typedef Bstnode *Bstnodeptr;


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


Bstnodeptr rotateRight(Bstnodeptr root)
{
	Bstnodeptr temp=root->left;
	root->left=temp->right;
	temp->right=root;

	return temp;
}

Bstnodeptr rotateLeft(Bstnodeptr root)
{
	Bstnodeptr temp=root->right;
	root->right=temp->left;
	temp->left=root;

	return temp;
}



Bstnodeptr splay(Bstnodeptr root, int data)
{
	if(root==NULL || root->data ==data)
		return root;

	//key lies in left subtree
	if(data<root->data)
	{
		if(root->left==NULL)
			return root;;

		if(data<root->left->data) //zig zig
		{
			//first recursively get data to root->left->left
			root->left->left=splay(root->left->left,data);

			//do first rotation now, second is done after else
			root=rotateRight(root);
		}
		else if(data>root->left->data) //zig zag
		{
			//get data to root->left->right
			root->left->right=splay(root->left->right,data);

			//if(do single rotation now) left
			if(root->left->right) //to prevent NULL from becoming parent
				root->left=rotateLeft(root->left);
		}

		return (root->left==NULL)?root:rotateRight(root); //second rotation
	}

	//data lies in the right subtree
	else 
	{
		if(root->right==NULL)
			return root;

		if(data> root->right->data) //zag zag
		{
			//first recursively bring data to root->right->right
			root->right->right=splay(root->right->right,data);

			//do first rotation now
			root=rotateLeft(root);
		}
		else if(data< root->right->data) //zag zig
		{
			//get data to root->right->left
			root->right->left=splay(root->right->left,data);

			//do sinle rotation now(right)
			if(root->right->left)
				root->right=rotateRight(root->right);
		}

		return root->right==NULL?root:rotateLeft(root); //second rotation
	}
}



Bstnodeptr search(Bstnodeptr root, int data)
{
	return splay(root, data);
}



Bstnodeptr newnode(int data)
{
	Bstnodeptr temp=(Bstnodeptr)malloc(sizeof(Bstnode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

Bstnodeptr insert(Bstnodeptr root, int data)
{
	if(root==NULL)
		return newnode(data);

	root = splay(root,data); //splay for the data
	if(root->data==data) //duplicate, already present
		return root;
	
	Bstnodeptr temp=newnode(data);

	if(data<root->data) // make root right child nd soon
	{
		temp->right=root;
		temp->left=root->left;
		root->left=NULL;
	}
	else if(data>root->data) //make root left child nd soon
	{
		temp->left=root;
		temp->right=root->right;
		root->right=NULL;
	}

	return temp;
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
		printf("inorder: ");
		inorder(root);
		printf("\n");
		printf("preorder: ");
		preorder(root);
		printf("\n");

	}
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;

		root=search(root, data);
		printf("inorder after splaying: ");
		inorder(root);
		printf("\n");
		printf("preorder after splaying: ");
		preorder(root);
		printf("\n");
	}

	return 0;
}
