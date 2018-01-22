#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define num_v 140000

//std::ios::sync_with_stdio(false); 

vector< vector<int> > graph(num_v);
vector< vector<int> > reverse_graph(num_v);
vector<int> finishing_times(num_v);
vector<int> visited(num_v);
vector<int> kosaraju(num_v);
vector<int> topological(num_v);
vector<int> dp(num_v);
map<int,int> is_rep;
int assign_number;


int main()
{	
	void store_finishing_time(int cur);
	void assign_kosaraju(int,int);
	void topological_sort(int);

	int test;
	cin>>test;

	while(test--)
	{	
		int n,m;
		cin>>n>>m;

		fill(finishing_times.begin(), finishing_times.begin()+n, 0);
		fill(kosaraju.begin(), kosaraju.begin()+n, 0);
		fill(topological.begin(), topological.begin()+n, 0);
		fill(dp.begin(), dp.begin()+n, 0);
		
		rep(i,m)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			graph[a].pb(b);
			reverse_graph[b].pb(a);
		}

		assign_number = 0;

		fill(visited.begin(), visited.begin()+n, 0);
		rep(i,n)
		{
			if(visited[i] == 0)
			{
				store_finishing_time(i);
			}
		}
		// Assigned finishing times


		// rep(i,n)
		// {
		// 	cout<<finishing_times[i]<<" ";
		// }
		// cout<<"\n";

		fill(visited.begin(), visited.begin()+n, 0);
		rep(i,n)
		{
			if(visited[finishing_times[n-i-1]] == 0)
			{
				assign_kosaraju(finishing_times[n-i-1], finishing_times[n-i-1]);
			}
		}
		// Assign strongly connected component to each vertex


		// rep(i,n)
		// {
		// 	cout<<kosaraju[i]+1<<" ";
		// }
		// cout<<"\n";

		map<int,int> count_per_component;
		rep(i,n)
		{
			if(count_per_component.find(kosaraju[i]) == count_per_component.end())
			{
				count_per_component[kosaraju[i]] = 1;
			}
			else
			{
				count_per_component[kosaraju[i]] += 1;
			}

			is_rep[kosaraju[i]] = 1;
		}

		// auto it = is_rep.begin();
		// while(it != is_rep.end())
		// {
		// 	cout<<it->first<<" ";
		// 	it++;
		// }
		// cout<<"\n";

		assign_number = 0;
		fill(visited.begin(), visited.begin()+n, 0);
		rep(i,n)
		{
			if(visited[i] == 0)
			{
				topological_sort(i);
			}
		}

		// rep(i,assign_number)
		// {
		// 	cout<<topological[i]<<" ";
		// }
		// cout<<"\n";
		fill(dp.begin(), dp.begin()+n, 0);

		for(int i=assign_number-1;i>=0;--i)
		{
			auto it = graph[topological[i]].begin();
			while(it != graph[topological[i]].end())
			{
				if((dp[kosaraju[(*it)]] > 0)||(count_per_component[topological[i]] > 1))
				{
					dp[topological[i]] = 1;
				}
				it++;
			}
		}

		// rep(i,n)
		// {
		// 	cout<<dp[i]<<" ";
		// }
		// cout<<"\n";

		int final_answer = 0;

		for(int i=0;i<n;++i)
		{
			auto it = graph[i].begin();
			while(it != graph[i].end())
			{
				if(dp[kosaraju[(*it)]] > 0)
				{
					final_answer++;
				}
				it++;
			}
		}

		cout<<final_answer<<"\n";

		rep(i,n)
		{
			graph[i].erase(graph[i].begin(), graph[i].end());
			reverse_graph[i].erase(reverse_graph[i].begin(), reverse_graph[i].end());
		}

		is_rep.erase(is_rep.begin(), is_rep.end());

	}
} 

void store_finishing_time(int cur)
{	
	// cout<<"Current Vertex : "<<cur+1<<"\n";
	auto it = reverse_graph[cur].begin();
	visited[cur] = 1;

	while(it != reverse_graph[cur].end())
	{
		if(visited[(*it)] == 0)
		{
			store_finishing_time((*it));
		}
		it++;
	}

	finishing_times[assign_number] = cur;
	assign_number++;
}

void assign_kosaraju(int cur, int to_assign)
{
	auto it = graph[cur].begin();
	visited[cur] = 1;
	kosaraju[cur] = to_assign;

	while(it != graph[cur].end())
	{
		if(visited[(*it)] == 0)
		{
			assign_kosaraju((*it), to_assign);
		}
		it++;
	}
}

void topological_sort(int cur)
{
	auto it = graph[cur].begin();
	visited[cur] = 1;

	while(it != graph[cur].end())
	{
		if(visited[(*it)] == 0)
		{
			topological_sort((*it));
		}
		// else if(visited[(*it)] == 0)
		// {
		// 	visited[(*it)] = 1;
		// }
		it++;
	}	

	// cout<<"Current Vertex : "<<cur+1<<"\n";
	// cout<<"Size of the map : "<<is_rep.size()<<"\n";

	if(is_rep.find(cur) != is_rep.end())
	{
		topological[assign_number] = kosaraju[cur];
		assign_number++;
		// cout<<"Here\n";
	}

}