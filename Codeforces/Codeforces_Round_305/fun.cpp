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
vi scores;
int n,m,q;

int main()
{	
	// int scores();
	void update_row(int);
	// int n,m,q;
	cin>>n>>m>>q;
	graph.resize(n);
	scores.resize(n);
	fill(scores.begin(), scores.end(), 0);

	rep(i,n)
	{
		graph[i].resize(m);
	}

	rep(i,n)
	{
		rep(j,m)
		{
			cin>>graph[i][j];
		}
	}

	rep(i,n)
	{
		update_row(i);
	}

	rep(i,q)
	{
		int x,y;
		cin>>x>>y;
		graph[x-1][y-1] = 1 - graph[x-1][y-1];
		update_row(x-1);

		cout<<*(max_element(scores.begin(), scores.end()))<<endl;
	}


} 

// int scores(void)
// {

// }

void update_row(int row)
{
	int i=0;
	int answer = 0;

	while(i<m)
	{	
		int temp = 0;
		if(graph[row][i])
		{
			while(graph[row][i]&&(i<m))
			{
				temp++;
				i++;
			}
			i--;
			answer = max(answer, temp);
		}
		i++;
	}
	scores[row] = answer;
}