#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long exponent[100];

int main()
{	
	long long int number(long long int n,long long int k);
	long long int n,k;

	cin>>n>>k;

	exponent[0] = 1;

	for(int i=1;i<=63;++i)
	{
		exponent[i] = exponent[i-1]*2;
	}

	long long answer = number(n,k);
	cout<<answer<<"\n";


} 



long long number(long long int n,long long int k)
{
	if(n == 1)
	{
		return 1;
	}
	else
	{
		if(k == exponent[n-1])
		{
			return n;
		}
		else if(k < exponent[n-1])
		{
			return number(n-1,k);
		}
		else
		{
			return number(n-1,k-exponent[n-1]);
		}
	}
}