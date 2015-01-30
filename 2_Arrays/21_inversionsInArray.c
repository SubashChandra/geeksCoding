//count no of inversions in an array
//ie no of steps away from being a sorted array

//O(n*n)

#include<stdio.h>

int inversions(int a[], int n)
{
	int count =0;
	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
				count++;
		}
	}
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	printf("inversions : %d\n", inversions(a,n));

	return 0;
}
