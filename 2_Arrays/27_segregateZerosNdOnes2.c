//given a array with 0's nd 1's, arrange such that 0's occur before 1's
//using two indices from front and back

//O(n) time

#include<stdio.h>



void segregate(int a[], int n)
{
	int temp;
	int i=0;
	int j=n-1;

	while(i<j)
	{
		while(a[i]==0 && i<j)
			i++;

		while(a[j]==1 && i<j)
			j--;

		if(i<j) //swap 1's nd 0's
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}


}

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	segregate(a,n);

	printf("array after rearranging: \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}


