//equilibrium index is one whehn sumof elemenst to its left = sum of elements to its right
//calculate sum of array as right sum nd set left sum to 0
//iterate over the array, update left sum nd right sum, compare nd print


//O(n) time
//O(1) space


#include<stdio.h>

void printEquiIndexes(int a[], int n)
{
	int i,j;
	int leftSum=0;
	int sum=0,rightSum;

	for(i=0;i<n;i++)//compute sum of the array
		sum+=a[i];

	rightSum=sum;

	for(i=0;i<n;i++)
	{
		rightSum-=a[i];
		if(leftSum==rightSum) //compare
			printf("%di ",i);
		leftSum+=a[i]; //update left nd right sums
	}
	printf("\n");
}



int main()
{
	int n;
	scanf("%d",&n);

	int a[n],i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printEquiIndexes(a,n);

	return 0;
}
