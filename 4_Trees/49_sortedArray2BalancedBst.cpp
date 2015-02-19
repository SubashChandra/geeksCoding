//given a sorted array, generate a balanced bst out of it
//middle element as root, nd construct left nd right subtrees recursively

//O(n) time
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


Bstnodeptr newnode(int data)
{
	Bstnodeptr temp = (Bstnodeptr)malloc(sizeof(Bstnode));
	temp->data = data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

void preorder(Bstnodeptr root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


Bstnodeptr convertToBst(int a[], int l, int h)
{
	if(l>h) 
		return NULL;

	int mid = (l+h)/2; //make mid node root, nd populate left nd right recursively
	Bstnodeptr temp = newnode(a[mid]);

	temp->left = convertToBst(a,l,mid-1);
	temp->right=convertToBst(a,mid+1,h);

	return temp;
}


int main()
{
	int n;
	scanf("%d",&n);
	int a[n];

	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	Bstnodeptr root = convertToBst(a,0,n-1);

	preorder(root);
	printf("\n");

	return 0;
}

