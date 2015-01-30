//given an array of size n+2, with elements in the range 1 to n
//find the two repeating elements

//brute-force approach
//O(n*n) time


#include<stdio.h>


void findRepeat(int a[], int n)
{
	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j]) //if element is repeated
				printf("%d ",a[i]);
		}
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	findRepeat(a,n);

	return 0;
}
