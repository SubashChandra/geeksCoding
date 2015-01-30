//majority element  is the array element which occurs more than half no of times
//using map 

//for every element if exists, increment count; else insert
//now iterate over the map if (*i).second >n/2 then (*i).first is the majority element

//O(n) time
//O(n) space for hash table


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>

using namespace std;

int majority(int a[], int n)
{
	map<int,int> m1;
	map<int,int>::iterator iter;

	int i;
	for(i=0;i<n;i++)
	{
		iter=m1.find(a[i]);
		if(iter==m1.end())
		{
			m1.insert(pair<int,int>(a[i],1));//if first occurrence, insert
		}
		else
		{
			(*iter).second++; //else increment its count
		}
	}

	for(iter=m1.begin();iter!=m1.end();iter++)//iterate over the hash map nd check conditon
	{
		if((*iter).second > n/2) //if is the majority element
		{
			return (*iter).first; //return element
		}
	}
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
