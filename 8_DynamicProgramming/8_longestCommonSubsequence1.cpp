//longest common subsequence given stwo strings
//time: exponential

#include<cstdio>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int lcs(string str1, string str2, int n, int m)
{
	if(n==-1 || m==-1)
		return 0;

	if(str1[n]==str2[m])
		return 1+lcs(str1,str2,n-1,m-1);

	else 
		return max(lcs(str1,str2,n-1,m),lcs(str1,str2,n,m-1));

}



int main()
{
	string str1,str2;
	cin>>str1>>str2;

	int n,m;
	n=str1.size();
	m=str2.size();
	printf("lcs: %d\n",lcs(str1,str2,n-1,m-1));

	return 0;
}
