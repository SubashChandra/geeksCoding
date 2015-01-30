//given 2 sorted arrays, find its union nd intersection (in sorted order)
//O(m+n) time

#include<stdio.h>

void printUnion(int a[], int m, int b[], int n)
{
	int i,j;

	i=0;
	j=0;

	printf("union: ");
	//while both are not empty, comapre nd print
	while(i<m && j<n)
	{
		if(a[i]==b[j]) //if same, print nd incrment both 
		{
			printf("%d ",a[i]);
			i++;
			j++;
		}
		else if(a[i]<b[j])
		{
			printf("%d ",a[i]);
			i++;
		}
		else
		{
			printf("%d ",b[j]);
			j++;
		}
	}

	//only oen of the following loops will be executed

	while(i<m)
	{
		printf("%d ",a[i]);
		i++;
	}

	while(j<n)
	{
		printf("%d ",b[j]);
		j++;
	}
	printf("\n\n");
}

void printIntersection(int a[], int m, int b[], int n)
{
	int i=0,j=0;
	printf("intersection: ");

	while(i<m && j<n) //while both are not empty
	{
		if(a[i]==b[j]) //if equal print, else skip
		{
			printf("%d ",a[i]);
			i++;
			j++;
		}

		else if(a[i]<b[j])
			i++;

		else
			j++;
	}
	printf("\n\n");
}

int main()
{
	printf("array1: ");

	int m,n;
	scanf("%d",&m);

	int i;
	int a[m];
	for(i=0;i<m;i++)
		scanf("%d", &a[i]);

	printf("array2: ");
	scanf("%d",&n);

	int b[n];
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);

	printUnion(a,m,b,n);
	printIntersection(a,m,b,n);
	return 0;
}
