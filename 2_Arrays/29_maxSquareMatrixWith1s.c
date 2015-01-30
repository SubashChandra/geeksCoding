//given a matrix with 0's nd 1's, fnd the max square matrix with all ones
//O(n*n) time
//O(n*n) space (for an auxillary matrix)

#include<stdio.h>

int min(int a, int b, int c)
{
	int ans=a;
	if(b<ans)
		ans=b;
	if(c<ans)
		ans=c;
	return ans;
}

void maxSquareMatrix(int *a, int m, int n)
{
	int i,j;

	int b[m][n]; //auxillary matrix
	//first copy first row and column to the auxillary matrix
	for(i=0;i<n;i++) //first row
	{
		b[0][i]=*((a+0*n)+i);
	}
	
	for(i=0;i<m;i++) //first column
	{
		b[i][0]=*((a+i*n)+0);
	}

	int data;
	for(i=1;i<m;i++) //fill up rest of teh auxullary array
	{
		for(j=1;j<n;j++)
		{
			data = *((a+n*i)+j);
			if(data == 1)
			{
				b[i][j]=min(b[i-1][j],b[i][j-1],b[i-1][j-1])+1;
			}
			else
				b[i][j]=0;
		}
	}

	printf("aux matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}

	//now find max in aux matrix
	int max=b[0][0];
	int xMax=0;
	int yMax=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i][j]>max) //get max element and its coordiantes
			{
				max=b[i][j];
				xMax=i;
				yMax=j;
			}
		}
	}

	//use it to print the matrix

	printf("\nmax sub array is:\n");
	for(i=xMax;i>xMax-max;i--)
	{
		for(j=yMax;j>yMax-max;j--)
		{
			printf("%d  ",*((a+i*n)+j));
		}
		printf("\n");
	}


}






int main()
{
	int m,n; //mxn matrix
	scanf("%d %d",&m,&n);

	int i,j;
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{	
			scanf("%d", &a[i][j]);
		}
	}

	maxSquareMatrix((int *)a,m,n); //using a single pointer (typecast while passing)

	return 0;
}
