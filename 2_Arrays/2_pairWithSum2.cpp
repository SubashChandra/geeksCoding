//given an array and x, check if sum of any two elements in the array = x
//using hash map

//O(n) time 
//O(n) space for hash table


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>

using namespace std;

//check if two elements with sum "sum" are present
int check(int a[], int n, int sum)
{
	map<int,int> m1;
	map<int,int>::iterator i;
	int j;

	for(j=0;j<n;j++)
	{
		i=m1.find(sum-a[j]); //for every element x, check if sum-x is in map
		if(i==m1.end()) //if not insert x in map
		{
			m1.insert(pair<int,int>(a[j],1)); 
		}
		else //else print both an return 1
		{
			printf("%d+%d=%d\n",a[j],(*i).first,sum);
			return 1;
		}
	}
	return 0; //else return 0

}


int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int x;
	scanf("%d",&x);

	printf("%s\n",check(a,n,x)?"yes":"no");

	return 0;
}
