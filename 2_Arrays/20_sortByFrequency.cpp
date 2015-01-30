//given an arraym sort its elements by frequency
//using map

//O(n*n) time
//O(n) space

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>


using namespace std;

int max(map<int,int>m1)
{
	int ans=0;
	map<int,int>::iterator i;
	for(i=m1.begin();i!=m1.end();i++)
	{
		if((*i).second > ans)
			ans=(*i).second;
	}
	return ans;
}


void sortByFreq(int a[], int n)
{
	map<int, int> m1;
	map<int, int>::iterator i;

	int j;
	for(j=0;j<n;j++)
	{
		i=m1.find(a[j]);

		if(i==m1.end()) //insert into map
		{
			m1.insert(pair<int,int>(a[j],1));
		}
		else //increment frequency
		{
			(*i).second++;
		}
	}
	int maxValue,k;

	//map has elements and frequencies
	while(m1.size()!=0) //until map is not empty
	{
		maxValue=max(m1); //max value in the map
		for(j=0;j<n;j++) //iterate over the array nd chec if the element is in map nd has the maxValue frequency
		{
			i=m1.find(a[j]);
			if(i!=m1.end() && (*i).second==maxValue)
			{
				for(k=0;k<maxValue;k++) //print the element maxValue times nd delete it from map
					printf("%d ",(*i).first);
				m1.erase(i);
			}
		}
	}
	printf("\n");
}


int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);


	printf("array sorted by freq: \n");
	sortByFreq(a,n);


	return 0;
}
