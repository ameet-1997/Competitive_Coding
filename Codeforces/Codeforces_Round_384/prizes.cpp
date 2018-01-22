#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > graph(200001);

int sum[200001];
int max_children[200001];

int max_leaf;

long long int final_answer = -9223372036854775807;

int main()
{	
	void calculate_sum(int i);
	void calculate_max(int i);
	int n;
	cin>>n;

	if(n == 1)
	{
		cout<<"Impossible\n";
	}
	else
	{	
		for(int i=1;i<=n;++i)
		{
			cin>>sum[i];
		}
		int x1,y1;
		for(int i=0;i<n-1;++i)
		{
			cin>>x1>>y1;
			graph[x1].push_back(y1);
			graph[y1].push_back(x1);
			max_children[i+1] = -9223372036854775807;
		}

		calculate_sum(1);

		max_leaf = -1000000001;

		for(int i=1;i<=n;++i)
		{
			if(graph[i].empty())
			{
				if(sum[i] > max_leaf)
				{
					max_leaf = sum[i];
				}
			}
		}

		calculate_max(1);


		cout<<final_answer<<"\n";
	}
} 


void calculate_sum(int i)
{
	vector<int>::iterator it = graph[i].begin();
	long long ans = 0;

	while((it != graph[i].end())&&((*it)!=i))
	{	
		calculate_sum(*it);
		ans = ans + sum[*it];
		if(sum[*it] > max_children[i])
		{
			max_children[i] = sum[*it];
		}
	}
	ans = ans + sum[i];
	sum[i] = ans;

	return;
}


void calculate_max(int i)
{	
	if(graph[i].empty())
	{
		if(sum[i] > final_answer)
		{
			final_answer = sum[i];
			return;
		}
	}

	long long check = sum[i];

	vector<int>::iterator it = graph[i].begin();

	long long max1 = max_children[i],max2 = -9223372036854775807;
	while(it!=graph[i].end())
	{	
		int count = 0;
		if((sum[*it] > max2)&&(count > 0))
		{	
			if((sum[*it] == max1)&&(count == 0))
			{
				count++;
			}
			else
			{
				max2 = sum[*it];
			}
			
		}
	}

	long long temp = max(max1+max2,check);
	if(temp > final_answer)
	{
		final_answer = check;
	}
	
}
