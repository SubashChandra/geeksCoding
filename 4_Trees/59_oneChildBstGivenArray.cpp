//given a preorder tarversal of a bst, check if its one child bst pr not
//O(n) time
//O(1) space


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


int isOneChildBst(int prefix[], int n)
{
	int min,max,pre;
	min=-10000;
	max=10000;
	pre=prefix[0];

	int i;
	for(i=1;i<n;i++)
	{
		if(prefix[i]<pre)
			max=pre;
		else if(prefix[i]>pre)
			min=pre;
		if(prefix[i]>max || prefix[i]<min)
			return 0;
		
		pre=prefix[i];
	}
	return 1;
}



int main()
{
	int n;
	scanf("%d",&n);

	int pre[n],i;
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);

	printf("%s \n",isOneChildBst(pre,n)?"yes":"no");

	return 0;
}


