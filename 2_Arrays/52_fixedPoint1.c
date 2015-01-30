//given an array , fidn the fixed point
//fixed point: if a[i]==i

//liner search
//O(n) time

#include<stdio.h>

int fixedPoint(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==i) //if found
		{
			return i;
		}
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

	printf("index is %d\n",fixedPoint(a,n));
	

	return 0;
}
