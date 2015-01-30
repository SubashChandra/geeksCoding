//given a sorted array nd x, find ceiling of x
//O(n) time
#include<stdio.h>

int _ceiling(int a[], int l, int h, int x)
{
	if(x<a[l]) //if x is less than lowest of array a[]
		return l;
	
	int i;
	for(i=0;i<h;i++)
	{
		if(a[i]==x) //if element found
			return i;

		if(x>a[i] && x<=a[i+1]) //if lies in range
			return i+1;
	}
	return -1; //if x is greater than the lasrgest of array a[]
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
