//given an array of integers nd two numbers x and y, find the min distance between them

//find the first occurrence of x or y in the array nd store it as prev
//now iterate the array from the next position, if a[i] nd a[prev] are same update prev=i
//else update minDist variable as the diff of indices nd set prev=i

//O(n) time
//O(1) space


#include<stdio.h>

int minDist(int a[], int n, int x, int y)
{
	int minDist=n;
	int prev;
	int i;

	for(i=0;i<n;i++) //set prev to the first occurence of x or y
	{
		if(a[i]==x || a[i]==y)
		{
			prev=i;
			i++;
			break;
		}
	}

	for( ;i<n;i++) //iterate array from the next index
	{
		if(a[i]==x || a[i]==y) //if x or y
		{

			if(a[i]!=a[prev] && minDist> (i-prev)) //if not the same as prev nd distance between indices is less than minDist, update nd update prev
			{
				minDist=i-prev;
				prev=i;
			}
			else //if a[i] same as a[prev], update prev
				prev=i;
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


	

