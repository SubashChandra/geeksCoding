//kadane's algo
//doesn't work if all elements are negative

//find the largest sum contiguous subarray
//using two variables max,maxEndingHere

//O(n) time

#include<stdio.h>

int findSum(int a[], int n)
{
	int maxSoFar=0; //max at any time
	int maxEndingHere=0; //max includin the curret eleemnt
	int i;

	for(i=0;i<n;i++)
	{
		maxEndingHere+=a[i]; //include current element into sum

		if(maxEndingHere<0) //if it is less than zero, reset it to 0
			maxEndingHere=0;

		else if(maxEndingHere>maxSoFar) //if maxSoFar is less than maxEndingHere, update maxSoFar
			maxSoFar=maxEndingHere;
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
