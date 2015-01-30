//given a sorted array and x, find if x is the majority element
//linear search to first occurrence of x (at index i), nd check if a[i+n/2] == x

//O(n) time

#include<stdio.h>

//array is sorted
int isMajority(int a[], int n, int x)
{
	int i;
	int lastIndex = (n%2==0?n/2:(n/2+1)); //to prevent out of range array index access //odd n/2+1 //even n/2

	for(i=0;i<lastIndex;i++)
	{
		if(a[i]==x) //first occurrence of x
			break;
	}

	if(a[i+n/2]==x) //if x is occuring more than n/2 times
		return 1;
	else 
		return 0;
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

	printf("%d is %s\n",x,(isMajority(a,n,x)?"majority":"not majority"));

	return 0;
}
