//given two sorted array of size n nd m+n, merge them
//m+n array has only m elements nd n -1's

//merge them using 3 index variables
//O(m+n) time
//O(1) space

#include<stdio.h>


void merge(int mPlusN[], int N[], int m, int n)
{
	//first move all elements to the end of mPlusN Array
	int i;
	int j=(m+n-1); //result array index 
	for(i=(m+n-1);i>=0; ) //index i to iterate over the array
	{
		if(mPlusN[i]!=-1)
		{
			mPlusN[j]=mPlusN[i];
			j--;
			i--;
		}
		else //ignore -1's
			i--;
	}

	//now compare both arrays and populate from beginning

	i=0; //merged array indx
	j=n; //index for m elements in mPlusN
	int k=0; //index of N array

	while(i<(m+n))
	{
		if((j<(m+n) && mPlusN[j] < N[k]) || k==n) //take from mPlusN array
		{
			mPlusN[i]=mPlusN[j];
			i++;
			j++;
		}
		else //take from N array
		{
			mPlusN[i]=N[k];
			i++;
			k++;
		}
	}
}


int main()
{
	int m,n,i;
	scanf("%d %d",&m,&n);
	int mPlusN[m+n],N[n];
	printf("mplusn array: \n");
	for(i=0;i<(m+n);i++)
		scanf("%d",&mPlusN[i]);

	printf("narray: \n");
	for(i=0;i<n;i++)
		scanf("%d",&N[i]);

	merge(mPlusN,N,m,n);
	printf("merged array:\n");
	for(i=0;i<m+n;i++)
		printf("%d ",mPlusN[i]);
	printf("\n");
	 
	return 0;
}
