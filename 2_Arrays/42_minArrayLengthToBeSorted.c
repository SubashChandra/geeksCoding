//given an array of integers, fidn the min length subarray a[s...e] that should be sprted to make the whole array sorted
//O(n) time

//start from index 0, find index s such that a[s]>a[s+1]
//start from index n-1, find index e st a[e]<a[e-1]
//fidn the min nd max values in a[s...e]
//now scan from 0 to s-1, nd update s to element index greater than min
//nd now scan from n-1 to e+1 nd update e to element index less than max
//print  s nd e

#include<stdio.h>


void printUnsorted(int a[], int n)
{
	int s=0;
	int e=n-1;

	int i,min, max;

	for(s=1;s<n-1;s++)
	{
		if(a[s]>a[s+1])
			break;
	}


	if(s==n-1)
	{
		printf("the array is already sorted\n");
		return ;
	}

	for(e=n-1;e>0;e--)
	{
		if(a[e]<a[e-1])
			break;
	}

	min=a[s];
	max=a[s];

	//find min and max in a[s....e]
	for(i=s+1;i<=e;i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}

	//first element from the beginnjing greater than max
	for(i=0;i<s;i++)
	{
		if(a[i]>min)
		{
			s=i;
			break;
		}
	}
	
	//first eleemnt from the end that is smaller than min
	for(i=n-1;i>e;i--)
	{
		if(a[i]<max)
		{
			e=i;
			break;
		}
	}



	//the unsorted subarray is 
	for(i=s;i<=e;i++)
		printf("%d ",a[i]);
	printf("\n");
}







int main()
{
	int n;
	scanf("%d",&n);

	int a[n],i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printUnsorted(a,n);

	return 0;
}		
