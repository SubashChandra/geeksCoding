//given an array, find two elements whose sum is close to zero
//O(n*n) time

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void sumCloseToZero(int a[], int n)
{
	int l,r; //to hold indexes of both the elements
	int sum, minSum;
	int i,j;

	if(n<2)
		return;

	l=0;
	r=1;
	minSum=a[l]+a[r];

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			sum=a[i]+a[j];
			if(abs(minSum) > abs(sum)) //if sum of currnt two elements is less than prev stored value
			{
				minSum=sum;
				l=i;
				r=j;
			}
		}
	}
	printf("the two elements with sum close to zero: %d %d\n",a[l],a[r]);
}

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	sumCloseToZero(a,n);
	return 0;
}
