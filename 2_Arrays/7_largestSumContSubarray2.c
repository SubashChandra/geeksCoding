//find the largest sum contiguous subarray
//dynamic prog paradigm

//handles all negative array
//O(n) time

#include<stdio.h>

int max(int a, int b)
{
	return (a>b?a:b);
}

int findSum(int a[], int n)
{
	int maxSoFar=a[0]; //keep trak of overall max
	int i;
	int currMax=a[0]; //max with cur element considered

	for(i=1;i<n;i++)
	{
		currMax=max(a[i],currMax+a[i]); //consider the past+ current or just current
		maxSoFar=max(maxSoFar,currMax); //either old max value or the new one`
	}
	return maxSoFar;
}


int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("largest contigous subarray sum is: %d\n",findSum(a,n));

	return 0;
}
