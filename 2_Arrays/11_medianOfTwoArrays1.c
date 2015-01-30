//given two arrays, find median
//simply by keeping track of 2 elements nd counting till n


//O(n) time
//O(1) space

#include<stdio.h>


//gonna be a even sized array after merging
//so median is mean of middle two elemets
int median(int a[], int b[], int n)
{
	int i,j,k,pre,cur;
	i=0; //array a index
	j=0; //array b index

	//to keep track of 2 middle elements
	pre=-1; 
	cur=-1;
	for(k=0;k<=n;k++)
	{
		//handle two base conditions upon which break

		if(i==n) //if end of array1 is reached
		{
			pre=cur;
			cur=b[0];
			break;
		}

		else if(j==n)  //if end of array2 is reached
		{
			pre=cur;
			cur=a[0];
			break;
		}

		if(a[i]<b[j])
		{
			pre=cur;
			cur=a[i];
			i++;
		}
		else
		{
			pre=cur;
			cur=b[j];
			j++;
		}
	}
	return (pre+cur)/2; //return median
}




int main()
{
	int n;
	scanf("%d",&n);

	int a[n],b[n];

	int i;
	printf("array 1:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("array 2:\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);

	printf("median is %d\n",median(a,b,n));

	return 0;
}

			
