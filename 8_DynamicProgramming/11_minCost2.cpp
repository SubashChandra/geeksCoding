//given a cost matrix nd position, find the mincost path from (0,0) to (m,n)
//tabulation (bottom up)
//O


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

int minCost(int **cost,int m,int n,int posx, int posy)
{

	int aux[m][n];
	//copy first row nd first column
	int i,j;

	aux[0][0]=cost[0][0];
	for(i=1;i<m;i++)
	{
		aux[i][0]=aux[i-1][0]+cost[i][0];
	}

	for(i=1;i<n;i++)
	{
		aux[0][i]=aux[0][i-1]+cost[0][i];
	}

	for(i=1;i<=posx;i++)
	{
		for(j=1;j<=posy;j++)
		{
			aux[i][j]=minimum(aux[i][j-1],aux[i-1][j],aux[i-1][j-1])+cost[i][j];
		}
	}
	
	printf("aux matrix for testing\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",aux[i][j]);
		}
		cout<<endl;
	}



	return aux[posx][posy];
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
	printf("min cost: %d\n",minCost(cost,m,n,posx,posy));

	return 0;
}

	
