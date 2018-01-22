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

vector< vi > table(1000);
vector< vi > dp(1000);

int main()
{	
	void recieve_input(int,int);
	int n,m;
	cin>>n>>m;

	rep(i,n)
	{
		table.resize(m);
		dp.resize(m);
		fill(dp[i].begin(), dp[i].end(), 0);
	}

	recieve_input(n,m);
}

void dfs(int current_i, int current_j, int current_letter)
{
	dp[current_i][current_j] = 2;

	int temp1, temp2;

	temp1 = current_i+1; temp2 = current_j+1;
	if(validate(temp1, temp2)&&(table[temp1][temp2] == (current_letter+1)%4))
	{
		if(table[temp1][temp2] == 2)
		{
			
		}
	}


}

void recieve_input(int n, int m)
{
	rep(i,n)
	{
		rep(j,m)
		{
			char c;
			cin>>c;

			switch(c)
			{
				case 'D':{table[i][j] = 0;break;}
				case 'I':{table[i][j] = 1;break;}
				case 'M':{table[i][j] = 2;break;}
				case 'A':{table[i][j] = 3;break;}
			}
		}
	}	
}