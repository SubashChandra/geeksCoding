//given a file with multiple paragraph each seperated by a new line nd each paragraph with different words (may repeat)
//check if there exists a paragraph which contains all the words in the file

//use map to keep track of unique elements in the file, word for key nd para no for value nd track maxdistinct elements so fat per paragraph

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<string>

using namespace std;

int main()
{
	char fileName[100];
	scanf("%s",fileName);

	FILE *f1 = fopen(fileName,"r");
	map<string,int>m1; //map to keep track of distinct words nd their para no
	map<string,int>::iterator i;
	int max=0; //maxDistinct elements in a para so far
	int cur=0; //distinct elements in teh cur paragraph

	int paraNo=1;
	
	char temp[50];
	//go throught the file one paragraph at a time 
	//break if the end of file is reached
	while(fscanf(f1,"%s",temp)!=EOF)
	{

		if(strcmp(temp,"***")==0) //end of paragraph, compare, increment paraNO nd reset variables
		{
			printf("paraNo: %d cur: %d  fileDistinct: %d***\n",paraNo,cur,m1.size());
			if(cur>max)
				max=cur;
			cur=0;
			paraNo++;
			continue;
		}//skip the rest of the loop
		
		i=m1.find(temp);

		if(i==m1.end()) //if first occurence
		{
			m1.insert(pair<string,int>(temp,paraNo));
			cur++;
		}
		else //if dup
		{
			if(i->second != paraNo) //if duplicate but from a differnt paragraph
			{
				i->second=paraNo; //update parano
				cur++;
			}
			else if(i->second == paraNo) //if dup form the same para, ignore
			{

			}
		}
	}

	fclose(f1);

	if(max==m1.size())
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
			


