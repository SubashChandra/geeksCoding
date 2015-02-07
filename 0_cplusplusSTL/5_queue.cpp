//push and pop elements from the queue

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;


int main()
{
	queue<int> q1;
	
	int data;

	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;
		q1.push(data);
	}

	printf("now poping all the elements of the queue:\n");
	while(q1.size()!=0)
	{
		printf("%d ",q1.front());
		q1.pop();
	}

	printf("\n");
	return 0;
}
	

