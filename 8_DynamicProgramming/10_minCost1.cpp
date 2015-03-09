//given a cost matrix nd position, find the mincost path from (0,0) to (m,n)
//exponential time


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int minimum(int a, int b, int c)
{
	int min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;

	return min;
}

int minCost(int **cost,int m,int n)
{
	if(m<0 || n<0)
		return 10000;
	if(m==0 && n==0)
		return cost[m][n];
	else
		return (cost[m][n]
			+ minimum(minCost(cost,m-1,n),minCost(cost,m,n-1),minCost(cost,m-1,n-1)));
}

int main()
{
	int m,n;
	cin>>m>>n;

	int **cost;
	
	int i,j;
	cost =(int **)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
	{
		cost[i]=(int*)malloc(sizeof(int)*n);
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}

	int posx,posy;
	cin>>posx>>posy;
	printf("min cost: %d\n",minCost(cost,posx,posy));

	return 0;
}

	
