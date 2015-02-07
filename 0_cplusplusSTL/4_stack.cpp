//push and pop elements from the stack

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>

using namespace std;


int main()
{
	stack<int> s1;
	
	int data;

	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
			break;
		s1.push(data);
	}

	printf("now poping all the elements of the stack:\n");
	while(s1.size()!=0)
	{
		printf("%d ",s1.top());
		s1.pop();
	}

	printf("\n");
	return 0;
}
	

