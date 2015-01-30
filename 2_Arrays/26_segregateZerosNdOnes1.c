//given a array with 0's nd 1's, arrange such that 0's occur before 1's
//using counters nd linear approach

//O(n) time

#include<stdio.h>



void segregate(int a[], int n)
{
	int i;
	int zeros=0;
	int ones=0;

	for(i=0;i<n;i++)
	{
		a[i]==0?zeros++:ones++; //count no of 0's nd 1's
	}
	i=0;
	while(zeros>0) //fill 0's
	{
		a[i]=0;
		zeros--;
		i++;
	}
	while(ones>0) //nd then 1's
	{
		a[i]=1;
		ones--;
		i++;
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


