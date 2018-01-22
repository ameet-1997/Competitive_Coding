#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int gcd(int,int);

	int n;
	cin>>n;

	for(int i=0;i<n;++i)
	{
		int a,b;
		cin>>a>>b;

		cout<<gcd(max(a,b),min(a,b))<<"\n";
	}


}


int gcd(int x,int y)
{
	if(x%y == 0)
	{
		return y;
	}
	else
	{
		return gcd(y,x%y);
	}
}