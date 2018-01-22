#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main()
{
	int test;
	cin>>test;
	vector< vector<char> > graph;
	
	for(int i=0;i<50;++i)
	{
		graph[i].resize(50);
	}
	
	while(test--)
	{
		int n;
		
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				cin>>graph[i][j];
			}
		}
	}	
	
	long long answer = 1;
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(graph[i][j] == '?')
			{
				
			}
		}
	}
}
