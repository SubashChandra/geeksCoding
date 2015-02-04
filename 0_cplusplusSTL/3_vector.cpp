//testing vector, insert a few integers and print them

#include<cstdio>
#include<iostream>
#include<vector>


using namespace std;


int main()
{
	int i,data;

	vector<int>v;
	
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;

		v.push_back(data);
	}

	for(i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");

	return 0;
}
