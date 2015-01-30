//find max diff of two elements such that larger elements appears after the smaller element
//we keep track of maxDiff nd minElement so far

//O(n) time

#include<stdio.h>

int maxDiff(int a[], int n)
{
	int max=a[1]-a[0];
	int minElement =a[0];
	int i,j;

	for(i=1;i<n;i++)
	{
		if(a[i]-minElement > max) //update maxDifference
			max=a[i]-minElement;

		if(a[i]<minElement)  //update minElement
			minElement = a[i];
	}

	return max;
}


int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	printf("Max diff is %d\n",maxDiff(a,n));
	return 0;

	return 0;
}
