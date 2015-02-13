//given a array that has level order of a bst, print inorder
//O(n) time

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


//recursive fucn to print
void printSorted(int a[], int left, int right)
{
	if(left>right) 
		return;

	//inorder traversal kind
	printSorted(a,2*left+1,right);
	printf("%d ",a[left]);
	printSorted(a,2*left+2,right);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]); //level order of a bst

	printSorted(a,0,n-1);
	cout<<endl;

	return 0;
}

