//inorder traversal iterative
//using stack


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


/*
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
*/

void preorder(Bstnodeptr root)
{
	stack<Bstnodeptr> s1;
	if(root==NULL)
	{
		printf("empty tree\n");
		return;
	}

	while(1)
	{
		while(root)
		{
			//preocess root
			printf("%d ",root->data);
			s1.push(root);

			//now proecess left child
			root=root->left;
		}

		if(s1.size()==0)
			break;

		//now process the right 
		root=s1.top();
		s1.pop();
		root=root->right;
	}
}


//inorder traversal iterative
void inorder(Bstnodeptr root)
{
	stack<Bstnodeptr> s1;
	if(root==NULL)
	{
		printf("empty tree\n");
		return;
	}

	while(1)
	{
		while(root)
		{
			//if ther is left child, keep pushing it to stack
			s1.push(root);
			root=root->left;
		}

		if(s1.size()==0)
			break;

		//process the root
		root=s1.top();
		s1.pop();

		printf("%d ",root->data);

		//now process teh right child
		root=root->right;
	}
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

	int data,choice;
	
	printf("enter 1 to insert, 2 to delete, 3 to print preorder nd 4 to exit :");
	scanf("%d",&choice);
	
	while(choice!=4)
	{
		switch(choice)
		{
			case 1: 
				printf("enter data to insert: ");
				scanf("%d",&data);
				root=insert(root,data);
				preorder(root);
				printf("\n");
				break;

			case 2:
				printf("enter data to delete: ");
				scanf("%d",&data);
				root=deletenode(root,data);
				preorder(root);
				printf("\n");
				break;

			case 3: 
				printf("inorder: ");
				inorder(root);
				printf("\n");
				printf("preorder: ");
				preorder(root);
				printf("\n");
				break;

		}
		printf("enter 1 to insert, 2 to delete, 3 to print preorder nd 4 to exit :");
		scanf("%d",&choice);
	}

	return 0;
}
