#include <iostream>
#include <math.h>


using namespace std;

int main()
{
	long long test;

	cin>>test;

	for(long long i=0;i<test;++i)
	{
		long long n;
		cin>>n;

		float answer;
		long long ans;

		answer = (-3 + sqrt(9+8*n))/2;
		ans = (long long)answer;

		if(answer == ans)
		{
			cout<<(ans+1)*ans/2+n-ans<<"\n";
		}
		else
		{
			cout<<2*n-2*ans<<"\n";
		}

	}
}
