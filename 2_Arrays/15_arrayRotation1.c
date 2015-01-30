//given an array nd value k, rotate array by k
//using temp array

//O(n) time
//O(k) space


#include<stdio.h>


void rotateArray(int a[], int n, int k)
{
	int temp[k]; //temp array
	int i;
	//copy k to a temp array
	for(i=0;i<k;i++)
		temp[i]=a[i];

	//move the rest to the front
	int j=0;
	for(i=k;i<n;i++)
	{
		a[j]=a[i];
		j++;
	}

	//append k from temp to the end of a
	for(i=0;i<k;i++)
	{
		a[j]=temp[i];
		j++;
	}

	return;
}



int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int k;
	scanf("%d",&k);

	//rotate array a by k
	rotateArray(a,n,k);

	printf("rotated array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}


