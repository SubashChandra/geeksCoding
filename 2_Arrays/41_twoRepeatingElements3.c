//given an array of size n+2, with elements in the range 1 to n
//find the two repeating elements

//using twoo formulae
//O(n) time
//O(1) space


#include<stdio.h>
#include<math.h>

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}


void findRepeat(int a[], int size)
{
	int S=0;
	int P=1;
	int D;
	int i;
	int n=size-2;
	int x,y;


	for(i=0;i<size;i++) //calculate sum nd product
	{
		S+=a[i];
		P*=a[i];
	}

	S=S- n*(n+1)/2; //sum of two elements
	P=P/fact(n); //pridyct if two elements

	D=sqrt(S*S - 4*P);
	x=(S+D)/2;
	y=(S-D)/2;

	printf("two repeating elements: %d nd %d\n",x,y);
}



int main()
{
	int n;
	scanf("%d",&n);

	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	findRepeat(a,n);

	return 0;
}
