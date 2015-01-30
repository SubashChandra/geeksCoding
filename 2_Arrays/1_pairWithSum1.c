//using sorting

//O(n2) time

#include<stdio.h>

//O(n2) time
void sort(int a[], int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)//loop n times
	{
		for(j=0;j<n-1;j++) //loop over 1 to n-1 elements
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}



//check if two elements with sum "sum" are present
int check(int a[], int n, int sum)
{
	int i,j;
	sort(a,n); //first sort the array

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	//initialize variables to two extremes nd compare to sum
	i=0;
	j=n-1;
	while(i<j)
	{
		if(a[i]+a[j]==sum)//if found
		{
			printf("%d+%d=%d\n",a[i],a[j],sum);
			return 1;
		}
		else if(a[i]+a[j]>sum)
			j--;
		else
			i++;
	}
	return 0; //if not found

}





int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int x;
	scanf("%d",&x);

	printf("%s\n",check(a,n,x)?"yes":"no");

	return 0;
}
