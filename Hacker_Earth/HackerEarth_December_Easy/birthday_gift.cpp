#include <iostream>

using namespace std;

#define mod (1000*1000+3)

int a[1000],b[1000];

int c[26][26];

int main()
{
	int n,m;

	cin>>n>>m;

	char c1,c2;

	for(int i=0;i<m;++i)
	{
		cin>>c1>>c2;
		if(c1 != c2)
		{
			c[c1-'A'][c2-'A'] = c[c2-'A'][c1-'A'] = 1;
		}
	}

	

	if(n%2!=0)
	{
		cout<<"0\n";
	}
	else
	{
		
	}
} 
