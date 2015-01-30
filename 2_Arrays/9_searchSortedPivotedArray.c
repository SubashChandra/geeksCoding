//search a sorted nd pivoted array in logn

//find pivot using binary search
//find element using binary search
//O(logn) time

#include<stdio.h>



int findPivot(int a[], int low, int high)
{
	if(low>high)
		return -1;
	if(low==high)
		return low;

	int mid=(low+high)/2;

	if(mid<high && a[mid]>a[mid+1]) //if mid is pivot
		return mid;

	else if(mid>low &&a[mid-1]>a[mid]) //if mid-1 is pivot
		return mid-1;

	//else go recursively find pivot
	if(a[low]>=a[mid]) //check low tp mid-1
		return findPivot(a,low,mid-1);
	else
		return findPivot(a,mid+1,high);
}


//binary search
int binarySearch(int a[], int low, int high, int num)
{
	if(low>high)
		return -1;

	int mid=(low+high)/2;
	if(a[mid]==num)
		return mid;
	else if(num>a[mid])
		return binarySearch(a,mid+1,high,num);
	else
		return binarySearch(a,low, mid-1,num);
}



int pivotedSearch(int a[], int n, int num)
{
	int pivot = findPivot(a,0,n-1);
	if(pivot==-1) //not rotated at all
		return binarySearch(a,0,n-1,num);

	if(a[pivot]==num)
		return pivot; //if pivot is the search value
	else if(num>=a[0]) //search first half 
		return binarySearch(a,0,pivot-1,num);
	else //or second
		return binarySearch(a,pivot+1,n-1,num);
}



int main()
{
	int n;
	scanf("%d",&n);

	int a[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int num;
	scanf("%d",&num);

	printf("%d\n",pivotedSearch(a,n,num));

	return 0;
}


