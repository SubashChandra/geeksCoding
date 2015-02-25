//selection sort
//find the min in the remaining array nd get it to beginning

//O(n2) time

#include<stdio.h>
#include<stdlib.h>


void selectionSort(int arr[], int n)
{
	int i,j;
	int min, temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++) //itearet nd find curmin
		{
			if(arr[j]<arr[min])
				min=j;
		}
		//swap
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];

	int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	//sort array
	selectionSort(arr,n);

	printf("sortedArray:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
