//given an array of size n+2, with elements in the range 1 to n
//find the two repeating elements

//using count array
//O(n) time
//O(n) space


#include<stdio.h>


void findRepeat(int a[], int n)
{
	int count[n-2];
	int i;
	for(i=0;i<n-2;i++) //an auxillary to keep track of count
		count[i]=0;

	for(i=0;i<n;i++)
	{
		if(count[a[i]-1]==1) //if repeating (-1 cause indxing starts from 0
			printf("%d ",a[i]);
		else 
			count[a[i]-1]++;
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
