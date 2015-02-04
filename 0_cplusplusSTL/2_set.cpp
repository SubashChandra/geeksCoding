//remove duplictes in a string using set

#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;


int main()
{
	char a[100];

	set<char>s;
	set<char>::iterator i;

	int j,k;
	k=0;
	scanf("%s",a);
	printf("before %s\n",a);
	for(j=0;j<strlen(a);j++)
	{
		i=s.find(a[j]);

		if(i==s.end()) //first occurrence
		{
			s.insert(a[j]);
			a[k++]=a[j]; //insert if first occurrence


		}
	}
	a[k]='\0';
	printf("after %s\n",a);

	printf("elements in the set are:\n");
	for(i=s.begin();i!=s.end();i++)
		printf("%c ",*i);
	printf("\n");


	return 0;
}
