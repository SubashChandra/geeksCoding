//bubble sort
//O(n2) time

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n)
{
	int pass,i,temp;
	//to prevent taking O(n2) even in best case use a flag to check if swapping is done, nd stop if spapping is not done
	int flag=1;
	for(pass=n-1;pass>0 && flag;pass--)
	{
		flag=0; //deset flag nd set only if there is a swap
		for(i=0;i<pass;i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				flag=1;
			}
		}
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
	bubbleSort(arr,n);


	printf("sortedArray:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
