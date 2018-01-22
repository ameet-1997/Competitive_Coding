#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prlls 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prlls xxx77
//setprecision - cout << setprecision (4) << f << endl; Prlls x.xxxx

using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< ll >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< ll,ll >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<ll,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< ll,vi ,greater< ll > >

//std::ios::sync_with_stdio(false); 

vl numbers(1000000);
vl next_max(1000000);
vl next_min(1000000);
vl dp1(1000000);
vl dp2(1000000);
vl cumulative(1000000);

int main()
{	
	void get_next_max(ll n);
	void get_next_min(ll n);
	ll n;
	cin>>n;

	rep(i,n)
	{
		cin>>numbers[i];
	}

	get_next_max(n);
	get_next_min(n);

	dp1[0] = numbers[0];

	f(i,1,n)
	{	
		if(next_max[i]!= -1)
		{
			dp1[i] = numbers[i]*(i- next_max[i]);
			dp1[i] %= mod;			
			dp1[i] += dp1[next_max[i]];
			dp1[i] %= mod;
		}
		else
		{
			dp1[i] = numbers[i]*(i+1);
			dp1[i] %= mod;
		}
	}

	dp2[n-1] = numbers[n-1];

	fd(i,n-2,0)
	{
		if(next_min[i]!=-1)
		{
			dp2[i] = numbers[i]*(next_min[i] - i);
			dp2[i] %= mod;
			dp2[i] += dp2[next_min[i]];
			dp2[i] %= mod;
		}
		else
		{
			dp2[i] = numbers[i]*(n-i);
			dp2[i] %= mod;
		}
	}

	ll answer = 0;

	cumulative[n-1] = dp2[n-1];

	fd(i,n-2,0)
	{
		cumulative[i] = cumulative[i+1] + dp2[i];
		cumulative[i] %= mod;
	}

	f(i,0,n-1)
	{
		answer += dp1[i]*cumulative[i+1];
		answer %= mod;
	}

	cout<<answer<<endl;

} 


void get_next_max(ll n)
{
	stack< pii > next;
	fill(next_max.begin(), next_max.end(), -1);

	fd(i,n-1,0)
	{
		while(!next.empty()&&(next.top().first <= numbers[i]))
		{
			next_max[next.top().second] = i;
			next.pop();
		}

		next.push(mp(numbers[i], i));
	}

	// rep(i,n)
	// {
	// 	cout<<next_max[i]<<" ";
	// }
	// cout<<endl;
}

void get_next_min(ll n)
{
	stack< pii > next;
	fill(next_min.begin(), next_min.end(), -1);

	f(i,0,n)
	{
		while(!next.empty()&&(next.top().first >= numbers[i]))
		{
			next_min[next.top().second] = i;
			next.pop();
		}

		next.push(mp(numbers[i], i));
	}

	// rep(i,n)
	// {
	// 	cout<<next_min[i]<<" ";
	// }
	// cout<<endl;	
}