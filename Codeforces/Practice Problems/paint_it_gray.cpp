#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[200000];

vector< vector<int> > graph(200000);

int main()
{
	int n;
	cin>>n;

	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}

	int x1,y1;
	for(int i=0;i<n-1;++i)
	{
		cin>>x1>>y1;
		graph[x1].push_back(y1);
		graph[y1].push_back(x1);
	}	//Graph constructed

	



} 
