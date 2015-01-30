//find missing number in the sequence of numbers from 1 to n+1
//doing exor of all the array elemnets and numbers from 1 to n+1

//O(n) time

#include<stdio.h>


void printMissing(int a[], int n)
{
	int ans=0;
	int i;
	for(i=1;i<=n+1;i++)
		ans=ans^i; //1 to n+1
	for(i=0;i<n;i++)
		ans=ans^a[i]; //array elements

	printf("Missing Number is: %d\n",ans);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printMissing(a,n);

	return 0;
}
