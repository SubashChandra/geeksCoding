//given a number n,  nd a array of size k, generate all k-array strings of length n
//backtracking
//O(k^n) time

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;


void printStr(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d",arr[i]);
	printf("\n");
}

void binary(int arr[], int k, int n,int size)
{
	int i;
	if(n<1)
		printStr(arr,size);
	else
	{
		for(i=0;i<k;i++)
		{
			arr[n-1]=i;;
			binary(arr,k,n-1,size);
		}
	}
}


int main()
{
	int i,n,k;
	cin>>n;

	cin>>k;
	int arr[n];

	binary(arr,k,n,n);
	return 0;
}
