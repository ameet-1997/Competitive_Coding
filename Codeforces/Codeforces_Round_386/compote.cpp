#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int a,b,c;

	cin>>a>>b>>c;

	int co1 = a;
	int co2 = b/2;
	int co3 = c/4;

	int maxi = min(co1,min(co2,co3));

	cout<<7*maxi<<"\n";
}

