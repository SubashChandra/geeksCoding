//given an array of integers, find the contiguous subarray that has the largest sum
//O(n) time
//O(1) space


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


int largestContSum(int arr[], int n)
{
	int maxSum=arr[0];
	int curSum=arr[0];

	int i;

	for(i=1;i<n;i++)
	{
		curSum=max(curSum+arr[i],arr[i]); //since seq must be cont, either sofar+cur or just cur must be considered
		maxSum=max(curSum,maxSum); //update max so far
	}

	return maxSum;
}

int main()
{
	int n;
	cin >>n;

	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	printf("%d\n",largestContSum(arr,n));
	return 0;
}
