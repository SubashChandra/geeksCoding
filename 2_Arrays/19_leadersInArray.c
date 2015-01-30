//an element is leader if it is greater than all elements to its right
//scan from right nd keep track of maxElement till then

#include<stdio.h>

void printMajority(int a[], int n)
{
	int i;
	int maxSoFar=a[n-1]; //from right
	printf("%d ",a[n-1]); //print rightmost element

	for(i=n-2;i>=0;i--)
	{
		if(a[i]>maxSoFar) //if curr element is greater than maxFromRight, print it nd update maxSoFar
		{
			printf("%d ", a[i]);
			maxSoFar=a[i];
		}
	}
	printf("\n");
}


int main()
{
	int n;
	scanf("%d", &n);

	int a[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	printMajority(a,n);

	return 0;
}


