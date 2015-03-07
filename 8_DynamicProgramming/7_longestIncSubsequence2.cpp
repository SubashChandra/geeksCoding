//longest increasing subsequence 
//tabulation

//O(n^2) time
//O(n) time

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;



int lic(int arr[], int n)
{
	int aux[n];
	int i,j;
	for(i=0;i<n;i++)
		aux[i]=1;

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++) //for all the elemenets j before i, if they are less than arr[i] nd lic[j]+1 >lic[i],lic[i]=lic[j]+1
		{
			if(arr[j]<arr[i] && aux[j]+1>aux[i])
				aux[i]=aux[j]+1;
		}
	}

	int max=1;
	for(i=0;i<n;i++)
	{
		if(aux[i]>max)
			max=aux[i];
	}
	return max;

}


int main()
{
	int n;
	cin>>n;
	int i;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	printf("lic: %d\n",lic(arr,n));

	return 0;
}

