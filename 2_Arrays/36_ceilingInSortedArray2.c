//given a sorted array nd x, find ceiling of x
//using binary search

//O(logn) time
#include<stdio.h>

int _ceiling(int a[], int l, int h, int x)
{
	if(x>a[h])//no ceiling
		return -1;

	if(x<=a[l]) //if less than a[l]
		return l;

	int mid=(l+h)/2;

	if(x==a[mid]) //if match
		return mid;
	
	else if(x>a[mid]) //if greater
	{
		if((mid+1)<=h && x<=a[mid+1]) //if in range
			return mid+1;
		else //go recursive
			return _ceiling(a,mid+1,h,x);
	}

	else
	{
		if((mid-1)>=l && x>a[mid-1]) //if in range
			return mid;
		else //go recursive
			return _ceiling(a,l,mid-1,x);
	}


}

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	int x;
	scanf("%d",&x);
	int ans=_ceiling(a,0,n-1,x);

	if(ans==-1)
		printf("there is no ceiling for %d\n",x);
	else
		printf("ceiling of %d is %d\n",x,a[ans]);

	return 0;
}
