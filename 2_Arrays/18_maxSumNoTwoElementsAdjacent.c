//given an arrray fo positive integers, find max sum such that no two eleements are adjacent
//using two variables inc nd exc

//O(n) time


#include<stdio.h>


int maxSum(int a[], int n)
{
	int inc=a[0];
	int exc=0;
	int exc_new;

	int i;
	for(i=1;i<n;i++)
	{
		exc_new= (inc>exc?inc:exc); //store new exc value, can;t do later cause inc value gets modified in the next statement

		inc = exc+a[i];
		exc = exc_new; //update exc
	}

	return (inc>exc?inc:exc); //return max of both
}



int main()
{
	int n;
	scanf("%d", &n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);


	printf("max sum is %d\n",maxSum(a, n));
	return 0;
}
