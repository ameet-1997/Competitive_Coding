#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int temperature[1000000];

int main()
{
	int n,k;
	cin>>n>>k;

	int summer = 0;

	for(int i=0;i<n;++i)
	{
		cin>>temperature[i];
		if(temperature[i] >= 0)
		{
			summer++;
		}
	}

	if(summer + k < n)
	{
		cout<<"-1\n";
	}
	else
	{
		
	}

}
