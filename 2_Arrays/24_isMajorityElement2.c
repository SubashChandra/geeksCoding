//given a sorted array and x, find if x is the majority element
//binary search to first occurrence of x (at index i), nd check if a[i+n/2] == x

//O(logn) time

#include<stdio.h>

//fidn the first occurrence of x using binary search
int binarySearch(int a[], int l, int h, int x)
{
	int mid;
	if(h>=l)
	{
		//check if mid is the first occurrence of x
		mid=(l+h)/2;

		if(mid==0 || (a[mid-1]<x && a[mid]==x))
			return mid;

		else if(x>a[mid]) //go to second half
			return binarySearch(a,mid+1,h,x);
		else //or first 
			return binarySearch(a,l,mid-1,x);
	}
	return -1;
};



//array is sorted
int isMajority(int a[], int n, int x)
{
	int i = binarySearch(a,0,n-1,x);

	if(i==-1)
		return 0;
	
	if((i+n/2) <= (n-1) && a[i+n/2]==x) //if index is in range nd if matched with i+n/2 index
		return 1;
	else 
		return 0;

}


int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	int x;
	scanf("%d",&x);

	printf("%d is %s\n",x,(isMajority(a,n,x)?"majority":"not majority"));

	return 0;
}
