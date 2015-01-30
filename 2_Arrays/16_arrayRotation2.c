//given an array nd value k, rotate array by k
//rotate one element at a time

//O(n*k) time
//O(1) space


#include<stdio.h>

//rotate one element at a time
void rotateArray(int a[], int n, int k)
{
	int i,j;
	int temp;

	//each time, remove element from front, shift elements and attach it at the end
	for(i=0;i<k;i++)
	{
		temp=a[0];
		for(j=0;j<n-1;j++) //shift
			a[j]=a[j+1];
		a[j]=temp; //append at end
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


