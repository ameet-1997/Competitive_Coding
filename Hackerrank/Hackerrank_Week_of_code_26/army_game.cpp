#include <iostream>

using namespace std;

int main()
{
	int n,m;

	cin>>n>>m;

	int answer;

	if(n%2 == 0)
	{
		if(m%2 == 0)
		{
			answer = n/2*m/2;
		}
		else
		{
			answer = n/2*(m-1)/2 + n/2;
		}
	}
	else
	{
		if(m%2 == 0)
		{
			answer = m/2*(n-1)/2 + m/2;
		}
		else
		{
			answer = (m-1)/2*(n-1)/2 + m/2 + n/2 + 1;
		}
	}

	cout<<answer<<"\n";
} 
