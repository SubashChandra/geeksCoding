//given a sorted array, find the no of occureences of x

//find the first occurrence nd last occurrence nd return difference

//O(log n) time
//O(1) space

#include<stdio.h>

//retun index of first occurrence of x
int first(int a[], int low, int high, int x)
{
	int mid;
	if(high>=low)
	{
		mid=(low+high)/2;

		if((mid==0 || x>a[mid-1]) && a[mid]==x) //if first element and is equal to x or if mid is the first occurrence
			return mid;

		else if(x>a[mid]) // this order is very imp
			return first(a,mid+1,high,x);

		else
			return first(a,low,mid-1,x);
	}
	return -1;
}

//return index of last occurrece of x
int last(int a[], int low, int high, int x, int n)
{
	int mid;
	if(high>=low)
	{
		mid=(low+high)/2;

		if((mid==n-1 || x<a[mid+1]) && a[mid]==x) //if last element nd is equal to x or if is the last occurrence
			return mid;

		else if(x<a[mid]) //order of else if nd else is very important
			return last(a,low, mid-1, x,n);
		else 
			return last(a,mid+1, high, x,n);
	}
	return -1;
}


void printCount(int a[], int n, int x)
{
	int ind1=first(a,0,n-1,x);
	if(ind1==-1)
	{
		printf("%d is not present\n",x);
		return;
	}

	int ind2=last(a,0,n-1,x,n);

	printf("no of occurrences is %d\n",(ind2-ind1+1));
}


	


int main()
{
	int n;
	scanf("%d", &n);

	int a[n],i;
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int x;
	scanf("%d",&x);

	printCount(a,n,x);

	return 0;
}

