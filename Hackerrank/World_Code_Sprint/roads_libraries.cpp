#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int components[100000];
int visited[100000];

vector< vector<int> > graph(100000);

int main()
{	
	void dfs(int parent,int cur);
	
	int queries;
	cin>>queries;

	for(int zz=0;zz<queries;++zz)
	{

		int n,m,clib,croad;
		cin>>n>>m>>clib>>croad;

		for(int i=0;i<n;++i)
		{
			visited[i] = 0;
			components[i] = 0;
		}

		for(int i=0;i<100000;++i)
		{
			graph[i].clear();
		}

		int x1,y1;
		for(int j=0;j<m;++j)
		{
			cin>>x1>>y1;
			graph[x1-1].push_back(y1-1);
			graph[y1-1].push_back(x1-1);
		}

		for(int i=0;i<n;++i)
		{
			if(visited[i] == 0)
			{
				dfs(i,i);
			}
		}

		long long answer = 0;
		for(int i=0;i<n;++i)
		{
			if(components[i] > 0)
			{
				answer = answer + min(croad*(components[i]-1)+clib,clib*components[i]);
			}
		}

		cout<<answer<<"\n";
	}
}


void dfs(int parent,int cur)
{	
	visited[cur]= 1;
	components[parent]++;

	vector<int>::iterator it = graph[cur].begin();

	while(it!=graph[cur].end())
	{
		if(visited[*it] == 0)
		{
			dfs(parent,*it);
		}
		it++;
	}

	return;
}
