//longest common subsequence given stwo strings
//tabulation (bottom up dp)

//O(mn) time
//O(mn) space

#include<cstdio>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int lcs(string str1, string str2, int m, int n)
{

	int i,j;
	int aux[m+1][n+1];
	for(i=0;i<=m;i++)
		aux[i][0]=0;
	for(i=0;i<=n;i++)
		aux[0][i]=0;

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				aux[i][j]=1+aux[i-1][j-1];

			}
			else
			{
				aux[i][j]=max(aux[i-1][j],aux[i][j-1]);
			}
		}

	}
	return aux[m][n];

}



int main()
{
	string str1,str2;
	cin>>str1>>str2;

	int n,m;
	m=str1.size();
	n=str2.size();
	printf("lcs: %d\n",lcs(str1,str2,m,n));

	return 0;
}
