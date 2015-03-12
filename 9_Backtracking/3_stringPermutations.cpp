//given a string print all its permuatations
//O(n!) time
//O(n) space

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;


void swap(char *x, char*y)
{
	char temp=*x;
	*x=*y;
	*y=temp;
}

void permu(char str[], int l, int r, int *count)
{
	if(l==r)
	{
		(*count)++;
		printf("%s\n",str);
		return;
	}
	
	else
	{
		int i;
		for(i=l;i<r;i++)
		{
			swap(&str[l],&str[i]);
			permu(str,i+1,r,count);
			swap(&str[i],&str[l]);
		}
	}
}


int main()
{
	int n;
	cin >>n;
	char str[n];
	scanf("%s",str);

	int count=0;
	permu(str,0,n,&count);
	printf("count: %d\n",count);
	return 0;
}
