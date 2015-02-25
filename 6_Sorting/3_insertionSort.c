//isnertion sort
//min no od swaps compared to other twp N2 alogos
//get an element, copy till its corect slot is found nd insert it there

//O(n2) time

#include<stdio.h>
#include<stdlib.h>


void insertionSort(int arr[], int n)
{
	int i,j,data,temp;

	for(i=1;i<n;i++)
	{
		data=arr[i];
		j=i;
		while(j>0 && arr[j-1]>data) //iterate back nd copy until correct slot for data is found
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=data; //slot found
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
	insertionSort(arr,n);

	printf("sortedArray:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
