#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;

	const long long int check = 1000*1000*1000;

	if(n == 1)
	{
		cout<<"-1\n";
	}
	else if(n*(n+1) <= check)
	{
		cout<<n<<" "<<n+1<<" "<<n*(n+1)<<"\n";
	}
} 
