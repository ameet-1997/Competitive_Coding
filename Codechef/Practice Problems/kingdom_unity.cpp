#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[3000][3000];

int main()
{
	int test;
	cin>>test;


	int n,m,k;

	for(int zz = 0;zz < test;++zz)
	{
		cin>>n>>m>>k;

		int x1,y1;

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				graph[i][j] = 0;
			}
		}

		for(int i = 0;i<m;++i)
		{
			cin>>x1>>y1;
			graph[x1][y1] = graph[y1][x1] = 1;
		}

		

	}
} 
