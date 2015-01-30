//recursive way to reverse an array
//O(n) time

#include<stdio.h>

//recursive 
void reverseArray(int a[],int i,int j)
{
	if(i>=j)
		return;

	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;

	reverseArray(a,i+1,j-1); //go recursive

}



int main()
{
	int n;
	scanf("%d",&n);

	int a[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	reverseArray(a,0, n-1);

	printf("reversed array\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
