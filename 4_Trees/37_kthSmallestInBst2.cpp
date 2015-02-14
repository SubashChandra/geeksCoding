//given a bst, find the kth smallest element
//using modified structure which keeps track of no of nodes to the left of node
//O(n) time (worst case)
//O(n) space


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;
//modified node
struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
	int lno;
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
		newnode->lno=0;
		root = newnode;
	}

	else if(root->data == data)
		printf("duplicate\n");

	else if(data <root->data) //go recursive to the left subtree
	{
		root->lno++; //inserting to the left of node
		root->left=insert(root->left,data);
	}

	else //go recursive to teh right subtree
	{
		root->right=insert(root->right,data);
	}

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
	printf("%d %d(left)\n",root->data,root->lno);
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

//recursive
int kthSmallest(Bstnodeptr root, int k) //*count to keep track of no of nodes preocessed so far
{

	if(root==NULL)
		return -1;
	
	else
	{
		if(root->lno+1 ==k)
			return root->data;

		else if(k>root->lno) // find  kth smallest in left subtree
		{
			return kthSmallest(root->right,k-(root->lno+1));
		}

		else 
		{
			return kthSmallest(root->left,k);
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

	int k;
	scanf("%d",&k);
	printf("kth smallest: %d\n", kthSmallest(root,k));

	return 0;
}
