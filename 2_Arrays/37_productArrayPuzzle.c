//given an array a[], construct a prod[] array st prod[i] is product of all array elements except a[i]
//without using '/' op nd in O(n) time


//O(n) time
//O(n) space

#include<stdio.h>

void construct(int a[], int prod[], int n)
{
	int left[n]; //product of all elements to the left of a[i]
	int right[n]; //to the right of a[i]

	left[0]=1;
	right[n-1]=1;

	int i;
	for(i=1;i<n;i++) //populate left
		left[i]=left[i-1]*a[i-1];

	for(i=n-2;i>=0;i--) //populate right
		right[i]=right[i+1]*a[i+1];

	for(i=0;i<n;i++) //prod = left*right
		prod[i]=left[i]*right[i];
}

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	int prod[n];
	construct(a,prod,n);

	printf("prod array: ");
	for(i=0;i<n;i++)
		printf("%d ",prod[i]);
	printf("\n");

	return 0;
}
