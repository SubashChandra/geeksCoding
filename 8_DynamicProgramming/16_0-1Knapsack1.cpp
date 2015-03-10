//given a set of weights nd values nd a capacity W of knapsack, get th emax value that can be bor eby the knapsack using the weights

//naive: either include a weight or don;t include it

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}


int maxVal(int weights[], int values[], int n, int cap)
{
	if(n==0 || cap==0)
		return 0;

	if(weights[n-1]>cap) //if weight is greater than knapsack cap, dont include it
		return maxVal(weights,values,n-1,cap);

	else //else get max of including or not includeing nth weight
	{
		return max(maxVal(weights,values,n-1,cap),values[n-1]+maxVal(weights,values,n-1,cap-weights[n-1]));	
	}
}



int main()
{
	int n;
	cin >> n;

	int weights[n], values[n];

	int i;
	for(i=0;i<n;i++)
		cin>>weights[i];
	
	for(i=0;i<n;i++)
		cin>>values[i];



	int cap;
	cin>>cap;

	printf("max value: %d\n",maxVal(weights,values,n,cap));

	return 0;
}
