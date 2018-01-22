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

vector<vi> graph(100000);
vi visited(100000);

ll set1 = 0, set2 = 0;
bool flag = true;

int main()
{	
	void bfs();
	ll n;
	cin>>n;

	fill(visited.begin(), visited.end(), 0);

	rep(i,n-1)
	{
		ll x,y;
		cin>>x>>y;
		x--;y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	bfs();

	ll answer = set1*set2 - n + 1;

	cout<<answer<<endl;
} 


void bfs()
{
	queue<ll> q;

	q.push(0);
	q.push(-1);
	flag = true;
	visited[0] = 1;
	set2++;

	while(true)
	{
		if(q.front() == -1)
		{
			q.pop();
			q.push(-1);

			flag = !flag;

			if(q.front() == -1)
			{
				break;
			}
		}
		else
		{
			ll temp = q.front();
			// cout<<"Temp is: "<<temp<<endl;
			auto it = graph[temp].begin();

			while((it != graph[temp].end()))
			{	
				// cout<<"Inside"<<endl;
				if(visited[*it] == 0)
				{
					q.push(*it);
					visited[*it] = 1;
					if(flag)
					{
						set1++;
					}
					else
					{
						set2++;
					}					
				}

				it++;
			}

			q.pop();
		}
	}

}