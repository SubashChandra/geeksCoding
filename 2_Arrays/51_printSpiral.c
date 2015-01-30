//given an array m*n print it in spiral form
//O(m*n) time
//O(1) space


//using four variables nd 4 if conditions


#include<stdio.h>
#include<stdlib.h>


void printSpiral(int **a, int m, int n)
{
	int state=1;
	int i;

	int left=0, right=n-1;
	int top=0, bottom=m-1;

	while(left<right && top<bottom)
	{
		if(state==1) //top row
		{
			for(i=left;i<right;i++)
			{
				printf("%d ",a[top][i]);
			}
			state=2;
		}
		else if (state==2)  //right column
		{
			for(i=top;i<bottom;i++)
			{
				printf("%d ",a[i][right]);
			}
			state=3;
		}

		else if (state==3) //bottom row
		{
			for(i=right;i>left;i--)
			{
				printf("%d ",a[bottom][i]);
			}
			state=4;
		}

		else if (state==4) //left column
		{
			for(i=bottom;i>top;i--)
			{
				printf("%d ",a[i][left]);
			}
			state=1;

			//decrease the radius of teh spiral
			left++;
			right--;
			top++;
			bottom--;
		}
	}

	if(left==right) // print if there is a column to be tarversed
	{
		for(i=top;i<=bottom;i++)
			printf("%d ",a[i][left]);
	}

	else  //print if there is a row to be traversed
	{
		for(i=left;i<=right;i++)
			printf("%d ",a[top][i]);
	}
	printf("\n");

}
		
	



int main()
{
	int m,n;
	scanf("%d %d", &m,&n);

	int i,j;

	int **a=(int **)malloc(sizeof(int*)*m);

	for(i=0;i<m;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*n);
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printSpiral(a,m,n);

	return 0;
}

