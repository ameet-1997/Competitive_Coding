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

vector< vector<char> > table(500);
vector< vi > visited(500);
int n,m,k;


int main()
{	
	void dfs_k(int,int,int);
	cin>>n>>m>>k;

	rep(i,n)
	{
		table[i].resize(m);
		visited[i].resize(m);
		fill(visited[i].begin(), visited[i].end(), 0);
	}

	int start_i, start_j;
	int counter = 0;

	rep(i,n)
	{
		rep(j,m)
		{
			cin>>table[i][j];
			if(table[i][j] == '.')
			{
				start_i = i;
				start_j = j;
				counter++;
			}
		}
	}

	// cout<<"Value of the counter is : "<<counter<<"\n";
	// cout<<"The values of starts are : "<<start_i<<" : "<<start_j<<endl;

	dfs_k(start_i, start_j, counter - k);

	rep(i,n)
	{
		rep(j,m)
		{
			if((table[i][j] == '.')&&(visited[i][j]==0))
			{
				cout<<"X";
			}
			else
			{
				cout<<table[i][j];
			}
		}
		cout<<endl;
	}

}

void dfs_k(int current_i, int current_j, int k)
{	
	bool validate(int,int);
	static int till = 0;
	till++;
	visited[current_i][current_j] = 1;

	// cout<<"In : "<<current_i<<" : "<<current_j<<endl;

	if(till >= k)
	{
		return;
	}

	if((validate(current_i, current_j+1)&&(table[current_i][current_j+1] == '.'))&&(visited[current_i][current_j+1] == 0))
	{
		dfs_k(current_i, current_j+1, k);
	}

	if(till >= k)
	{
		return;
	}

	if((validate(current_i, current_j-1)&&(table[current_i][current_j-1] == '.'))&&(visited[current_i][current_j-1] == 0))
	{
		dfs_k(current_i, current_j-1, k);
	}

	if(till >= k)
	{
		return;
	}

	if((validate(current_i-1, current_j)&&(table[current_i-1][current_j] == '.'))&&(visited[current_i-1][current_j] == 0))
	{
		dfs_k(current_i-1, current_j, k);
	}

	if(till >= k)
	{
		return;
	}

	if((validate(current_i+1, current_j)&&(table[current_i+1][current_j] == '.'))&&(visited[current_i+1][current_j] == 0))
	{
		dfs_k(current_i+1, current_j, k);
	}	

	if(till >= k)
	{
		return;
	}
}


bool validate(int i, int j)
{
	if((i>=0)&&(i<n)&&(j>=0)&&(j<m))
	{
		return true;
	}
	else
	{
		return false;
	}
}
