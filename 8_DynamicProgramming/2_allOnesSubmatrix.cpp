//given a matrix, print the max square summatrix with all ones
//O(n^2) time
//O(1) spaxce


#include<cstdio>
#include<cstdlib>
#include<iostream>


using namespace std;

int min(int a, int b, int c)
{
	int min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;

	return min;
}

void printSubarray(int **arr,int m, int n)
{
	int i,j;
	int aux[m][n];

	for(i=0;i<m;i++)
	{
		aux[i][0]=arr[i][0];
	}
	for(i=0;i<n;i++)
	{
		aux[0][i]=arr[0][i];
	}

	int max=0,xInd=0,yInd=0;;
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(arr[i][j]==0)
			{
				aux[i][j]=0;
			}
			else
			{
				aux[i][j]=min(aux[i][j-1],aux[i-1][j],aux[i-1][j-1])+1;
				if(aux[i][j]>max)
				{
					max=aux[i][j];
					xInd=i;
					yInd=j;
				}

			}
		}
	}
	
	for(i=xInd-max+1;i<=xInd;i++)
	{
		for(j=yInd-max+1;j<=yInd;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}




}


int main()
{
	int m,n;
	cin >>m >> n;

	int **arr =(int **)malloc(sizeof(int*)*m);
	int i,j;

	for(i=0;i<m;i++)
	{
		arr[i]=(int*)malloc(sizeof(int)*n);
	}


	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	printSubarray(arr,m,n);
	return 0;

}
