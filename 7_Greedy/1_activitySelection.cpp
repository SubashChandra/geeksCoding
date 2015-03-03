//given a list of activities with start nd finish times, find the list nd max no of activities that can be performed by one person
//sort th eactivities based on finish time
//select an activity if it has least finish time among rest nd has start time greater than prev avtivity

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


int maxActivities(int s[], int f[], int n)
{
	int count=0;
	//assumih activities are already by finish times
	int pre=0; //first activi selected
	printf("%d ",pre);
	count++;
	int i;
	for(i=1;i<n;i++)
	{
		if(s[i]>=f[pre])
		{
			printf("%d ",i);
			count++;
			pre=i;
		}
	}
	printf("\n");
	return count;
}


int main()
{
	int n;
	cin>>n;

	int s[n],f[n];

	int i;
	for(i=0;i<n;i++)
		cin>>s[i];

	for(i=0;i<n;i++)
		cin>>f[i];

	printf("max activities: %d\n",maxActivities(s,f,n));
	return 0;
}
