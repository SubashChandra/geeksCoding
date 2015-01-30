//given a sorted array nd x, find floor of x
//using binary search

//O(log n) time
#include<stdio.h>

int _floor(int a[], int l, int h, int x)
{
	if(x>=a[h]) //base case
		return h;

	if(x<a[l]) //no floor
		return -1;

	int mid= (l+h)/2;

	if(a[mid]==x) //if matched
		return mid;

	if(x>a[mid]) //if greater than
	{
		if((mid+1)<=h && x<a[mid+1]) //if in this range
			return mid;
		else //go recursive
			return _floor(a,mid+1,h,x);
	}

	else //if less than
	{
		if((mid-1)>=l && x>=a[mid-1]) //if in this range
			return mid-1;
		else  //go recursive
			return _floor(a,l,mid-1,x);
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
	int ans=_floor(a,0,n-1,x);

	if(ans==-1)
		printf("there is no floor for %d\n",x);
	else
		printf("floor of %d is %d\n",x,a[ans]);

	return 0;
}
