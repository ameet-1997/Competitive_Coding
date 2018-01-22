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

int main()
{
	int n,m;
	cin>>n>>m;

	string s,t;
	cin>>s>>t;

	vector< vector<int> > to_replace(1000);
	vi number_replaced;

	int min_index = 0;
	int min_not_matched = INT_MAX;

	for(int i=0;i<=(m-n);++i)
	{
		int not_matched = 0;

		for(int j=0;j<n;++j)
		{
			if(s[j] != t[i+j])
			{
				to_replace[i].pb(j+1);
				not_matched++;
			}
		}

		if(not_matched < min_not_matched)
		{
			min_index = i;
			min_not_matched = not_matched;
		}
	}

	cout<<min_not_matched<<"\n";

	vector<int>::iterator it = to_replace[min_index].begin();

	while(it != to_replace[min_index].end())
	{
		cout<<(*it)<<" ";
		it++;
	}
	cout<<"\n";
} 
