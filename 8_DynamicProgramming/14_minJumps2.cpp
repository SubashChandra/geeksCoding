//given an array wpf integers where each element denotes the max no of jumps from that element forward
//if element uis 0, u cant move from taht e;ement

////naive
//create jumps array where jumps[i] tracks min jumps from arr[0] to arr[i]
#include<cstdio>
#include<cstdlib>
#include<iostream>

#define INTMAX 100000

using namespace std;


int minSteps(int arr[], int n)
{
	int jumps[n];
	int i,j;
	if(arr[0]==0 || n==0)
		return INTMAX;

	jumps[0]=0; //streps to reach arr[0] to arr[0]

	for(i=1;i<n;i++)
	{
		jumps[i]=INTMAX; //set it to INTMAX for the first time
		for(j=0;j<i;j++) 
		{
			if(i<= j+arr[j] && jumps[j]!=INTMAX) //if i is reachable from j nd jumps[j]!=INTMAX (ie there is no way to rech j)
			{
				jumps[i]=min(jumps[i],jumps[j]+1);
			}
		}
	}
	return jumps[n-1];
}



int main()
{
	int n;
	cin >>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	printf("steps: %d\n",minSteps(arr,n));

	return 0;
}
