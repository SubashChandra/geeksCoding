//fib(n)

//using a array to store computed values (bottom up)


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int fib(int n)
{
	int fib[n+1],i;
	fib[0]=0;
	fib[1]=1;
	for(i=2;i<=n;i++)
		fib[i]=fib[i-1]+fib[i-2];

	return fib[n];
}

	


int main()
{
	int n;
	cin>>n;

	printf("%d\n",fib(n));

	return 0;
}
