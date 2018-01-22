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

vector< vi > matrix(11);

int main()
{	
	int n;
	cin>>n;

	

	rep(i,n)
	{
		matrix[i].resize(n);
		fill(matrix[i].begin(), matrix[i].end(),0);
	}

	
	f(i,0,n)
	{
		f(j,0,n)
		{
			if((i == 0)&&(j == 0))
			{
				matrix[0][0] = 1;
			}
			else if(i == 0)
			{
				matrix[i][j] = matrix[i][j-1];
			}
			else if(j == 0)
			{
				matrix[i][j] = matrix[i-1][j];
			}
			else
			{
				matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
			}
		}
	}

	cout<<matrix[n-1][n-1];
}