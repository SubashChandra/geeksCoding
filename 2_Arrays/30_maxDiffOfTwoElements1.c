//find max diff of two elements such that larger elements appears after the smaller element
//comparing every element to every other elemnet

//O(n*n) time

#include<stdio.h>

int maxDiff(int a[], int n)
{
	int max=a[1]-a[0];
	int i,j;

	for(i=0;i<n-1;i++) //comapre each with every element afetr it
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]-a[i] > max) //if the second-first diff is greater than max
				max=a[j]-a[i];
		}
	}

	return max;
}


int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	printf("Max diff is %d\n",maxDiff(a,n));
	return 0;

	return 0;
}
