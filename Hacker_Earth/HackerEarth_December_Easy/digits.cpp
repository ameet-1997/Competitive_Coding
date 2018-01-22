#include <iostream>

using namespace std;

int main()
{
	long long x,k;
	cin>>x>>k;

	int a[30];

	int cur = 0;

	while(x)
	{
		a[cur] = x%10;
		x = x/10;
		cur++;
	}

	int count = 0;

	for(int j = cur-1;j>=0&&count<k;--j)
	{
		if(a[j] != 9)
		{
			a[j] = 9;
			count++;
		}

	}

	for(int j=cur-1;j>=0;--j)
	{
		cout<<a[j];
	}

	cout<<"\n";

	

	


} 
