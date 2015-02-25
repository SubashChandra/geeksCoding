//quick sort
//O(nlogn) time

#include<stdio.h>
#include<stdlib.h>

void swap(int arr[], int x, int y)
{
	int temp;
	temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}


int partition(int arr[], int left, int right)
{
	int pivotItem=arr[left];

	int l,r;
	l=left;
	r=right;

	while(l<r)
	{
		while(arr[l]<=pivotItem)
			l++;

		while(arr[r]>pivotItem)
			r--;

		if(l<r)
			swap(arr,l,r);
	}

	//now pivot position is r
	arr[left]=arr[r];
	arr[r]=pivotItem;

	return r;
}


void quickSort(int arr[], int left, int right)
{
	if(left<right)
	{
		int pivot=partition(arr,left,right);
		quickSort(arr,left,pivot-1);
		quickSort(arr,pivot+1,right);
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
	quickSort(arr,0,n-1);



	printf("sortedArray:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
