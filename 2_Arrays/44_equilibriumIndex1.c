//equilibrium index is one whehn sumof elemenst to its left = sum of elements to its right
//naive approach
//calculating left sum nd right sum for each element nd comparing them

//O(n*n) time
//O(1) space


#include<stdio.h>

void printEquiIndexes(int a[], int n)
{
	int i,j;
	int leftSum;
	int rightSum;

	for(i=0;i<n;i++)
	{
		leftSum=0;
		rightSum=0;

		for(j=0;j<i;j++) //calculate sum of elements to the left of a[i]
			leftSum+=a[j];


		for(j=i+1;j<n;j++) //to the right of a[i]
			rightSum+=a[j];

		if(leftSum==rightSum)
			printf("%d ",i);
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
