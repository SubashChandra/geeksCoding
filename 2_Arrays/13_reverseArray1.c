//iterative way to reverse an array
//O(n) time

#include<stdio.h>


void reverseArray(int a[], int n)
{
	int i=0; //from beginning
	int j=n-1; //from endng

	int temp;
	while(i<j) //swap elements at indexes i nd j
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}

	return;
}



int main()
{
	int n;
	scanf("%d",&n);

	int a[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	reverseArray(a,n);

	printf("reversed array\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
