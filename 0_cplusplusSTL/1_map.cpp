//remove duplictes in a string using map

#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;


int main()
{
	char a[100];

	map<char,int>m;
	map<char,int>::iterator i;

	int j,k;
	k=0;
	scanf("%s",a);
	printf("before %s\n",a);
	for(j=0;j<strlen(a);j++)
	{
		i=m.find(a[j]);

		if(i==m.end()) //first occurrence
		{
			m.insert(pair<char,int>(a[j],1));
			a[k++]=a[j]; //insert if first occurrence
		}
	}
	a[k]='\0';
	printf("after %s\n",a);

	printf("nd elements in map are:\n");
	for(i=m.begin();i!=m.end();i++)
		printf("%c ",i->first);
	printf("\n");


	return 0;
}
