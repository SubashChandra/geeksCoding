//given an array of integers nd two numbers x and y, find the min distance between them

//use two loops nd update minDist variable

//O(n*n) time
//O(1) space


#include<stdio.h>

int minDist(int a[], int n, int x, int y)
{
	int minDist,i,j;

	minDist=n;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(((a[i]==x && a[j]==y) || (a[i]==y && a[j]==x)) && minDist>(j-i)) //if both elements found, update minDist
			{
				minDist=j-i;
			}
		}
	}
	return minDist;
}


int main()
{
	int n;
	scanf("%d",&n);

	int a[n],x,y,i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	scanf("%d %d",&x,&y);

	printf("min distance is: %d\n",minDist(a,n,x,y));

	return 0;
}


	

