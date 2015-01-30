//majority element  is the array element which occurs more than half no of times
//moore's counting algorithm

//first check if thereis one nd then confirm it

//O(n) time
//O(1) space


#include<stdio.h>

int majority(int a[], int n)
{
	int majIndex=0; //assume majority element is at index 0
	int count=1;
	int i;

	//first determine if there is a majority element
	for(i=1;i<n;i++)
	{
		if(a[majIndex]==a[i]) //if same increment
			count++;
		else //else decrement count
			count--;

		if(count==0) //else assume current element as majority element nd set count to 1
		{
			majIndex=i;
			count=1;
		}
	}

	//now confirm it, else return -1
	int ans=a[majIndex];
	int temp=0; //counter
	for(i=0;i<n;i++)
	{
		if(a[i]==ans)
			temp++;
	}
	if(temp>n/2)
		return ans;
	else 
		return -1;
}



int main()
{
	int n;
	scanf("%d",&n);
	int a[n];

	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("majority element: %d\n",majority(a,n));

	return 0;
}
