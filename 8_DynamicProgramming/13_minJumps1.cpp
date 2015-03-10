//given an array wpf integers where each element denotes the max no of jumps from that element forward
//if element uis 0, u cant move from taht e;ement

////naive
//steps(start, end) = min(steps(k,end)) for all ks reachable from start
#include<cstdio>
#include<cstdlib>
#include<iostream>

#define INTMAX 100000

using namespace std;


int minSteps(int arr[], int l, int h)
{
	if(l==h)
		return 0;
	if(arr[l]==0) //no advance allowed
		return INTMAX;

	int i;
	int min=INTMAX; 
	for(i=l+1; i<=h && i<= l+arr[l];i++) //for all elements that are reachable from arr[l]
	{
		int jumps=minSteps(arr,i,h); //calcuale from k to h

		if(jumps!=INTMAX && jumps+1<min) //get min of all 
			min=jumps+1;
	}

	return min;
}




int main()
{
	int n;
	cin >>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	printf("steps: %d\n",minSteps(arr,0,n-1));

	return 0;
}
