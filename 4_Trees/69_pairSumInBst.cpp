//given a bst nd a sum , find if two elements exist, with the given sum
//using iterative inorder traversals, one from front nd other from back
//O(n) time
//O(n) space


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


int sumExists(Bstnodeptr root, int sum)
{
	if(root==NULL)
		return 0;

	int flag1=0;
	int flag2=0;

	stack<Bstnodeptr> s1;
	stack<Bstnodeptr> s2;

	Bstnodeptr root1,root2;
	root1=root2=root;

	int value1,value2;

	//do two inordertraversals one normal nd other reverse
	while(1)
	{
		while(flag1==0)
		{
			if(root1)
			{
				s1.push(root1);
				root1=root1->left;
			}
			else
			{
				if(s1.size()==0)
					flag1=1;
				
				else
				{
					root1=s1.top();
					s1.pop();
					value1=root1->data;
					root1=root1->right;
					flag1=1;
				}
			}
		}

		while(flag2==0)
		{
			if(root2)
			{
				s2.push(root2);
				root2=root2->right;
			}
			else
			{
				if(s2.size()==0)
					flag2=1;
				else
				{
					root2=s2.top();
					s2.pop();
					value2=root2->data;
					root2=root2->left;
					flag2=1;
				}
			}
		}

		//make sure same elements are not added
		if((value1!=value2) && (value1+value2)==sum)
		{
			printf("%d %d**\n",value1,value2);
			return 1;
		}
		else if(value1+value2<sum) //get next element in the inorder
			flag1=0;
		else if(value1+value2>sum)
			flag2=0; //get next element in reverse inorder
		
		if(value1>=value2) //not found
			return 0;
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
	
	int sum;
	while(1)
	{
		scanf("%d",&sum);
		if(sum==-1)
			break;

		printf("%s\n",sumExists(root,sum)?"exists":"doesn't exist");
	}
	return 0;
}
