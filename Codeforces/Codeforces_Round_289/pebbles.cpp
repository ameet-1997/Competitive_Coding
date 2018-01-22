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
	int n,k;
	cin>>n>>k;

	vi pebbles(n);

	rep(i,n)
	{
		cin>>pebbles[i];
	}

	int min_pebbles = *(min_element(pebbles.begin(), pebbles.end()));
	int max_pebbles = *(max_element(pebbles.begin(), pebbles.end()));

	int min_color, max_color;

	if(max_pebbles/k > min_pebbles/k + 1)
	{
		cout<<"NO\n";
	}
	else if((max_pebbles/k == min_pebbles/k + 1)&&(max_pebbles%k > min_pebbles%k))
	{
		cout<<"NO\n";
	}
	else
	{	
		cout<<"YES\n";
		rep(i,n)
		{
			int color = 0;

			rep(j, pebbles[i])
			{
				cout<<(color%k)+1<<" ";
				color++;
			}
			cout<<"\n";
		}
	}


}