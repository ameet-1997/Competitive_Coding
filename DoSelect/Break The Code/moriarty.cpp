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

//std::ios::sync_with_stdio(false); 

bool flag;
vector< vi > graph(100000);
vi visited(100000);

int main()
{	
	bool dfs(int);
	int test;
	cin>>test;

	while(test--)
	{	
		flag = true;
		int n,m;
		cin>>n>>m;

		rep(i,n)
		{
			graph[i].erase(graph[i].begin(), graph[i].end());
		}

		fill(visited.begin(), visited.begin()+n, 0);
		rep(i,m)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;

			graph[u].pb(v);
			graph[v].pb(u);
		}

		rep(i,n)
		{
			if(visited[i] == 0)
			{	
				visited[i] = 1;
				flag = flag && dfs(i);
			}

			if(!flag)
			{
				break;
			}
		}

		if(flag)
		{
			cout<<"It is possible."<<endl;
		}
		else
		{
			cout<<"It is not possible."<<endl;
		}
	}
}


bool dfs(int current)
{
	vector<int>::iterator it = graph[current].begin();

	while(it != graph[current].end())
	{
		if(visited[*it] == visited[current])
		{
			return false;
		}
		else if(visited[*it] == 0)
		{
			if(visited[current] == 1)
			{
				visited[*it] = 2;
			}
			else
			{
				visited[*it] = 1;
			}

			bool temp = dfs(*it);
			if(!temp)
			{
				return false;
			}
		}

		it++;
	}

	return true;
}
