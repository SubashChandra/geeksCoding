//mergeSort
//recursively go left nd rigt half nd merge them
//O(nlogn) time

#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int aux[], int left, int mid, int right)
{
	int leftEnd, index, begin;
	leftEnd=mid-1;
	index=left;
	begin=left; //store left index to copy back later

	while(left<=leftEnd && mid<=right)
	{
		if(arr[left]<=arr[mid])
		{
			aux[index]=arr[left];
			index++;
			left++;
		}
		else 
		{
			aux[index]=arr[mid];
			index++;
			mid++;
		}
	}

	while(left<=leftEnd)
	{
		aux[index]=arr[left];
		index++;
		left++;
	}

	while(mid<=right)
	{
		aux[index]=arr[mid];
		index++;
		mid++;
	}

	//now copy back 
	int i;
	for(i=begin;i<=right;i++)
	{
		arr[i]=aux[i];
	}
}



void mergeSort(int arr[],int aux[], int left, int right)
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		//go recursive left nd right halves
		mergeSort(arr,aux,left,mid);
		mergeSort(arr,aux,mid+1,right);
		
		//sorted merge them
		merge(arr,aux,left, mid+1, right);
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

	int aux[n];
	//sort array
	mergeSort(arr,aux,0,n-1);

	printf("sortedArray:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
