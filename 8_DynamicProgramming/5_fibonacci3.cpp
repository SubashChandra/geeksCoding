//fib(n)

//only storing last 2  computed values 


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int fib(int n)
{
	int i,a,b,c;
	a=0;
	b=1;
	if(n==0)
		return a;

	for(i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}

	return b;
}

	


int main()
{
	int n;
	cin>>n;

	printf("%d\n",fib(n));

	return 0;
}
