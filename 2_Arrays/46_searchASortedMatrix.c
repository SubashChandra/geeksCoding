//given a n*n matrix that is sorted both row and column wise, find x
//start at left bottom or right top nd move appropriately


//O(n) time
//O(1) space

#include<stdio.h>
#include<stdlib.h>

void find(int **a, int n, int x)
{
	//start at right top
	int i=0;
	int j=n-1;

	while(i<n && j>=0)
	{
		if(a[i][j]==x)
		{
			printf("%d %d\n",i,j);
			return;
		}

		if(x>a[i][j]) //go down
		{
			i++;
		}
		else //go left
		{
			j--;
		}
	}

	printf("%d not found\n",x);
}


int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int **a = (int **)malloc(sizeof(int *)*n);

	for(i=0;i<n;i++)
	{
		a[i]=(int*)malloc(sizeof(int)*n);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	int x;
	scanf("%d",&x);

	find(a,n,x);

	return 0;
}
	



