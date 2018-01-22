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

vector< vi > graph;
vi visited;
vector<double> storage;

int main()
{	
	double dfs(int);
	int n;
	cin>>n;

	graph.resize(n);
	visited.resize(n);
	storage.resize(n);

	double answer = 0;

	fill(visited.begin(), visited.begin()+n, 0);

	rep(i,n-1)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	// // Graph testing
	// rep(i,n)
	// {
	// 	for(vector<int>::iterator it = graph[i].begin();it != graph[i].end();++it)
	// 	{
	// 		cout<<(*it)+1<<" ";
	// 	}
	// 	cout<<endl;
	// }

	visited[0] = 1;
	answer = dfs(0);
	cout<<setprecision(10)<<answer<<"\n";
} 


double dfs(int current)
{
	// int sz = graph[current].size();
	
	int counter = 0;
	visited[current] = 1;

	auto it = graph[current].begin();

	double score = 0;
	while(it != graph[current].end())
	{	
		if(visited[*it] == 0)
		{
			visited[*it] = 1;
			score += (dfs(*it)+1);
			// storage[counter] = dfs(*it);
			counter++;			
		}
		it++;
	}

	// cout<<"Current node and counter value: "<<current+1<<" : "<<counter<<endl;

	if(counter == 0)
	{
		return 0.0;
	}

	// rep(i,counter)
	// {
	// 	score += (storage[i] + 1);
	// }

	double temp = score/counter;
	// cout<<"Current node and temp and score value: "<<current+1<<" : "<<temp<<" : "<<score<<endl;

	return temp;
	
}
