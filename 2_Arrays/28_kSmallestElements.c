//print k smallest elements elements in an array
//using modified bubble sort (outer loop k times)


//O(n*k)

#include<stdio.h>

void smallestK(int a[], int n, int k)
{
	int i;
	int j;
	int temp;

	for(i=0;i<k;i++) //only k times
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}

	for(i=0;i<k;i++)
		printf("%d ",a[i]);
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

	int k;
	scanf("%d",&k);

	smallestK(a,n,k);

	return 0;
}
