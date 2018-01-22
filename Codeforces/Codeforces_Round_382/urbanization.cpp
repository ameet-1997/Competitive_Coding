#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	int n,n1,n2;

	cin>>n>>n1>>n2;

	int a[100000];

	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}

	sort(a,a+n);

	double answer = 0;
	long long sum1 = 0;
	long long sum2 = 0;

	if(n1 >= n2)
	{
		for(int i=0;i<n2;++i)
		{
			sum1 = sum1 + a[n-1-i];
		}

		for(int i=0;i<n1;++i)
		{
			sum2 = sum2 + a[n-n2-1-i];
		}

	}
	else
	{
		for(int i=0;i<n1;++i)
		{
			sum2 = sum2 + a[n-1-i];
		}

		for(int i=0;i<n2;++i)
		{
			sum1 = sum1 + a[n-n1-1-i];
		}
	}

	answer = ((double)sum2)/n1 + ((double)sum1)/n2;

	//cout<<answer<<"\n";

	printf("%.8lf\n",answer);
} 
