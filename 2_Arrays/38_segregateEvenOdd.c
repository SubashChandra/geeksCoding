//given an array of even nd odds.segregate them st odd comes after even
//with two indexes

//O(n0 time

#include<stdio.h>


void segregate(int a[],int n)
{
	int l=0;
	int r=n-1;
	int temp;

	while(l<r)
	{
		while(a[l]%2==0  && l<r)//if even at beginning, skip
			l++;

		while(a[r]%2==1 && r>l) //if odd at end, skip
			r--;

		if(l<r) //swap data
		{
			temp=a[l];
			a[l]=a[r];
			a[r]=temp;
			l++;
			r--;
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

	printf("array after segregating even-odd: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
