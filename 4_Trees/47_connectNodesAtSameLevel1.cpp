//using a augmented bst, set level while inseting into queue nd conect nodes if they are of same level
//O(n) time
//O(n) space


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

struct bstnode
{
	int data;
	int level;
	struct bstnode *left;
	struct bstnode *right;
	struct bstnode *next;
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
		newnode->next=NULL;
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


//level order tarversal
void levelorder(Bstnodeptr root)
{
	if(root==NULL)
	{
		printf("empty tree\n");
		return;
	}
	
	queue<Bstnodeptr> q1;
	q1.push(root); //push root

	while(q1.size()!=0) //while not empty, pop nd print the front node of queue nd push its left nd right childs if any
	{
		root=q1.front(); 
		q1.pop();
		printf("%d ",root->data);

		if(root->left)
			q1.push(root->left);

		if(root->right)
			q1.push(root->right);
	}
}

void setNextPointer(Bstnodeptr root)
{
	queue<Bstnodeptr> q;
	Bstnodeptr next;
	root->level=1;
	q.push(root);

	while(q.size()!=0)
	{
		root=q.front();
		q.pop();

		//process cur node
		if(root->left)
		{
			root->left->level=root->level+1;
			q.push(root->left);
		}
		if(root->right)
		{
			root->right->level=root->level+1;
			q.push(root->right);
		}

		if(q.size()!=0 && q.front()->level == root->level) //if element exists after cuurent ndoe nd is of same level
		{
			root->next=q.front();
		}
		else
			root->next=NULL;
	}
}


//print tree using only next pointers
void printTree(Bstnodeptr root)
{
	Bstnodeptr cur;
	while(root)
	{
		cur=root;
		while(cur!=NULL) //print nodes at currnt level
		{
			printf("%d->",cur->data);
			cur=cur->next;
		}
		printf("NULL\n");
		root=root->left;
	}
}
	


int main()
{
	Bstnodeptr root = NULL;

	int data;
	
	
	printf("enter data to insertor -1: ");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;

		root=insert(root,data);
	}
	preorder(root);
	printf("\n");

	setNextPointer(root);

	printTree(root);

	return 0;
}
