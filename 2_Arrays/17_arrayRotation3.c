//given an array nd value k, rotate array by k
//using reversal algorithm

//O(n) time
//O(1) space


#include<stdio.h>

//iterative array reverse
void reverse(int a[], int i, int j)
{
	int temp;
	while(i<j) //swap first and last nd inc/dec indexes
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}

	return;
}


void rotateArray(int a[], int n, int k)
{
	//first reverse 0 to k-1
	reverse(a,0,k-1);

	//then reverse k to n-1
	reverse(a,k,n-1);

	//then reverse 0 to n-1
	reverse(a,0,n-1);
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


