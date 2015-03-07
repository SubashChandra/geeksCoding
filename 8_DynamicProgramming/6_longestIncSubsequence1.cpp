//longest increasing subsequence 
//exhaustive

//exponential time

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int auxLic(int arr[], int *max, int n)
{
	if(n==1)
		return 1;

	int maxEndingHere=1,res; //len of lic ending with arr[n-1]
	
	//rcursively get all lis ending with arr[0],arr[1]...arr[n-1]
	//if(arr[i-1] < arr[n-1] nd maxEndingHere for arr[n-1] need to be updated update it
	int i;

	for(i=1;i<n;i++)
	{
		res=auxLic(arr,max,i);
		if(arr[i-1]<arr[n-1] && res+1>maxEndingHere)
			maxEndingHere=res+1;
	}

	//compare maxEnding Here with overall max
	if(*max<maxEndingHere)
		*max=maxEndingHere;

	//return lis ending wth arr[n-1]
	return maxEndingHere;
}


int lic(int arr[], int n)
{
	int max=1;
	auxLic(arr,&max,n);
	return max;
}


int main()
{
	int n;
	cin>>n;
	int i;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	printf("lic: %d\n",lic(arr,n));

	return 0;
}

