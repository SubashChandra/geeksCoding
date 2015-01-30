//given an array of size n which contains elements from 0 to n-1, with each repeating any no of times
//do in O(n) time in O(1) space

//by in-place modiffication of array

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void printRepeating(int a[], int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(a[abs(a[i])]>=0) //if first occurrence of a[i], negate element at index a[i]
			a[abs(a[i])]*=-1;
		else //if element at index a[i] is already negative, this is a repeatitio
			printf("%d ",abs(a[i]));
	}
	printf("\n");
}

			


int main()
{
	int n;
	scanf("%d",&n);

	int a[n],i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printRepeating(a,n);

	return 0;
}
