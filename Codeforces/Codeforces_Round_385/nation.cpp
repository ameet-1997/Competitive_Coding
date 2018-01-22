#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[1000][1000];

int government[1000];

int component_with_government[1000];
int edges_with_government[1000];
int component_without_government[1000];
int edges_without_government[1000];
int visited[1000];

int n,m,k;

int main()
{	
	void dfs(int,int);
	int calculate_c(int);

	cin>>n>>m>>k;

	for(int i=0;i<k;++i)
	{
		cin>>government[i];
		government[i]--;
	}

	int x1,y1;
	for(int i=0;i<m;++i)
	{
		cin>>x1>>y1;
		graph[x1-1][y1-1] = 1;
		graph[y1-1][x1-1] = 1;
	}

	for(int i=0;i<k;++i)
	{
		dfs(government[i],government[i]);
	}

	int max_government = 0;

	for(int i=0;i<n;++i)
	{
		if(edges_with_government[i] > max_government)
		{
			max_government = edges_with_government[i];
		}

	}

	long long answer = 0;

	for(int i=0;i<n;++i)
	{
		answer = answer + calculate_c(edges_with_government[i]);
	}

	int mul = 0;

	for(int i=0;i<n;++i)
	{	
		if(visited[i] == 0)
		{
			mul++;
		}
	}

	answer = answer + max_government*mul;
	answer = answer + calculate_c(mul);
	answer = answer - m;

	cout<<answer<<"\n";
	
} 


void dfs(int parent,int cur)
{
	visited[cur] = 1;
	edges_with_government[parent]++;

	for(int i=0;i<n;++i)
	{
		if(graph[cur][i] == 1)
		{	
			if(visited[i] == 0)
			{
				dfs(parent,i);	
			}
			
		}
	}

	return;
}



int calculate_c(int n)
{
	return n*(n-1)/2;
}