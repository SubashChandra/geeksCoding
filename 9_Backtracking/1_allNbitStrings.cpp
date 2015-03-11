//given a number n, generate all binary strings of length n
//backtracking
//O(2^n) time

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

void binary(int n, int arr[], int size)
{
	if(n<1)
		printStr(arr,size);
	else
	{
		arr[n-1]=0;
		binary(n-1,arr,size);
		arr[n-1]=1;
		binary(n-1,arr,size);
	}
}


int main()
{
	int n;
	cin>>n;

	int arr[n];

	binary(n,arr,n);
	return 0;
}
