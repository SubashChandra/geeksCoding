//given two arrays, find median
//by comparing medians nd recursively selecting either half of each array

//O(logn) time
//O(n) space (recursion stack)

#include<stdio.h>


int max(int a, int b)
{
	return (a>b?a:b);
}

int min(int a,int b)
{
	return (a<b?a:b);
}


int median(int a[], int n)
{
	if(n%2==0) //if array of even size
	{
		return (a[n/2]+a[n/2-1])/2;
	}
	else
		return a[n/2];
}


//n is size of each array
int getMedian(int a[], int b[], int n)
{
	int m1; //median of array a
	int m2; //median of array b

	if(n<=0) 
		return -1;
	else if(n==1)
		return (a[0]+b[0])/2;
	else if(n==2)
		return (max(a[0],b[0])+min(a[1],b[1]))/2;

	m1=median(a,n);
	m2=median(b,n);

	if(m1==m2) //if medians are same, return value
		return m1;

	else if (m1<m2) //take second half of a, dn first half of b, nd go recursive
	{
		if(n%2==0)
		{
			return getMedian(a+n/2-1,b,n-n/2+1);
		}
		else
			return getMedian(a+n/2,b,n-n/2);
	}

	//m1>m2
	else //take first half of a nd second half of b, go recursve
	{
		if(n%2==0)
		{
			return getMedian(a, b+n/2-1, n-n/2+1);
		}
		else
			return getMedian(a, b+n/2, n-n/2);
	}

}




int main()
{
	int n;
	scanf("%d",&n);

	int a[n],b[n];

	int i;
	printf("array 1:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("array 2:\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);

	printf("median is %d\n",getMedian(a,b,n));

	return 0;
}

			
