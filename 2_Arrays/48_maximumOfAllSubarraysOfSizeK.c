//given an array of integers nd k, print the max of each subsets of size k

//O(k*n) time


#include<stdio.h>

//find the max of each k sized subarrays
void printMaxOfSubArrays(int a[], int n, int k)
{
	int i,j,max;

	for(i=0;i<=n-k;i++)
	{
		max=a[i]; //set first eelment of subarray as max
		for(j=1;j<k;j++) //now find the max among other k-1 elements of subarray
		{
			if(a[i+j]>max)
				max=a[i+j];
		}
		printf("%d ",max);
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

	int k;
	scanf("%d",&k);

	printMaxOfSubArrays(a,n,k);

	return 0;
}
