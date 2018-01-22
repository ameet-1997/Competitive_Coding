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

viii vouchers(1000000);
vii duration(1000000);

int main()
{
	int n,x;
	cin>>n>>x;

	rep(i,n)
	{
		cin>>vouchers[i].first;
		cin>>vouchers[i].second.first;
		cin>>vouchers[i].second.second;
	}

	sort(vouchers.begin(), vouchers.begin()+n);

	rep(i,n)
	{
		duration[i].first = vouchers[i].second.first - vouchers[i].first + 1;
		duration[i].second = i;
	}

	sort(duration.begin(), duration.begin()+n);

	int min_cost = INT_MAX;
	bool flag = false;

	rep(i,n)
	{
		int to_search = x - (vouchers[i].second.first - vouchers[i].first + 1);
		if(to_search)
		{
			int index1 = lower_bound(duration.begin(), duration.begin()+n, mp(to_search,0)) - duration.begin();
			int index2 = upper_bound(duration.begin(), duration.begin()+n, mp(to_search,INT_MAX)) - duration.begin();

			for(int j=index1;j<index2;++j)
			{
				if((vouchers[i].second.first < vouchers[duration[j].second].first)||(vouchers[duration[j].second].second.first < vouchers[i].first))
				{
					flag = true;
					min_cost = min(min_cost, (vouchers[i].second.second + vouchers[duration[j].second].second.second));
				}
			}
		}
	}

	if(flag)
	{
		cout<<min_cost<<"\n";
	}
	else
	{
		cout<<"-1\n";
	}
	

} 
