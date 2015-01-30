//given an array, find smallest nd second smallest elements
//using two variables first in second 

//O(n) time

#include<stdio.h>
#define INT_MAX 1000


void print2Smallest(int a[], int n)
{
	int first,second;
	first= INT_MAX;
	second = INT_MAX;
	int i;

	if(n<2)
	{
		printf("invalid array size\n");
		return;
	}


	for(i=0;i<n;i++)
	{
		if(a[i]<first) //if cure eleemnt is less than first, update both
		{
			second=first;
			first=a[i];
		}
		else if(a[i]<second && a[i]!=first) //if only less than second, update second
		{
			second=a[i];
		}
	}

	if(second == INT_MAX)
	{
		printf("no second min. %d is first smallest\n",first);
	}
	else
	{
		printf("two minimas are %d nd %d\n",first, second);
	}
}

	


int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	print2Smallest(a,n);

	return 0;
}
