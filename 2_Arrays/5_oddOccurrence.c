//find teh number occurring odd number of times
//even occurrences of each no cancel eachother

//using exor
//O(n) time
//O(1) space

#include<stdio.h>


int printOdd(int a[], int n)
{
	if(n%2==0) //for one odd occurrence, size should be odd`
		return -1; 
	
	//else
	int ans=0;
	int i;

	for(i=0;i<n;i++)
		ans=ans^a[i];//xor

	return ans;
}


int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("odd occring element is: %d\n",printOdd(a,n));

	return 0;
}

