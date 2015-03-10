//given a set of values coins nd amount n, get how many wasy to make change
//naive approach : either can include a coint or cant imprive a coin


//exponential time

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


int count(int coins[], int n, int sum)
{
	if(sum==0) 
		return 1; //1 sol, select no coins
	
	if(sum<0) //no solution 
		return 0;

	if(sum>=1 && n<=0) 
		return 0;

	return count(coins,n-1,sum)+count(coins,n,sum-coins[n-1]);
}


int main()
{
	int n;
	cin>>n;
	int coins[n];

	int i;
	for(i=0;i<n;i++)
		cin>>coins[i];

	int sum;
	cin>>sum;

	printf("count: %d\n",count(coins,n,sum));
	return 0;
}
