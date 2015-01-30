//given a sorted array nd x, find floor of x
//O(n) time
#include<stdio.h>

int _floor(int a[], int l, int h, int x)
{
	if(x > a[h]) //if greater than all array elements
		return h;
	int i;
	for(i=1;i<=h;i++)
	{
		if(x<a[i] && x>=a[i-1])
			return i-1;
	}
	return -1; //if x is less than a[0]
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
