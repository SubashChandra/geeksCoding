//given a string, find the longest substring without repeating characters
//O(n+d) time //where d is the no of chars in the input string alphabet
//O(d) space


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>


using namespace std;


int maxLen(string str)
{
	int n=str.size();
	int preIndex;
	int curLen=1;
	int maxLen=1;
	int i;
	int *visited = (int*)malloc(sizeof(int)*256);

	for(i=0;i<256;i++)
		visited[i]=-1; //to keep track of index where a char has occurred

	//assume first char as visite to start with
	visited[str[0]]=0; //char occurred at index 0

	for(i=1;i<n;i++)
	{
		preIndex=visited[str[i]];
		if(preIndex==-1 || (i-curLen)>preIndex) //char first occurrence or not part of current substring
		{
			curLen++;
		}

		else //char already occurred in the current substring
		{
			if(curLen>maxLen)
				maxLen=curLen;

			curLen=i-preIndex;
		}
		visited[str[i]]=i; //update the index of current of current charater
	}
	if(curLen>maxLen)
		maxLen=curLen;

	free(visited);
	return maxLen;
}

int main()
{
	string str;
	cin>> str;

	printf("max len: %d\n",maxLen(str));
	return 0;
}

	
