//given an array , fidn the fixed point
//fixed point: if a[i]==i

//binary search 
//O(log n) time

#include<stdio.h>

int fixedPoint(int a[],int low, int high)
{
	if(high>=low)
	{
		int mid=(low+high)/2;
		if(a[mid]==mid)
			return mid;
		else if(mid>a[mid])
			return fixedPoint(a,mid+1,high);
		else
			return fixedPoint(a,low,mid-1);
	}

	return -1; //not found
}


int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	printf("index is %d\n",fixedPoint(a,0,n-1));
	

	return 0;
}
