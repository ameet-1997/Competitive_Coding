#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


char flights[1000000];

int main()
{
	int n,a,b;

	cin>>n>>a>>b;
	cin>>flights;

	if(flights[a-1] == flights[b-1])
	{
		cout<<"0\n";
	}
	else
	{
		cout<<"1\n";
	}
} 
