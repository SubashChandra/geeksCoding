//given a set of weights nd values nd a capacity W of knapsack, get th emax value that can be bor eby the knapsack using the weights

//tabulation: bottom up
//O(nw) time
//O(w) space

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
	int aux[n+1][cap+1];

	int i,j;

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=cap;j++)
		{
			if(i==0||j==0)
				aux[i][j]=0;
			
			else if(weights[i-1]<=j) //take maxval of including or not including nth weight
				aux[i][j]=max(values[i-1]+ aux[i-1][j-weights[i-1]],aux[i-1][j]);
			
			else //igonore nth weight
				aux[i][j]=aux[i-1][j];
		}
	}
	return aux[n][cap];

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
