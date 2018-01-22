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

//vi numbers(10000000);
vector< pair<ll,ll> > segment_tree(30000000);

int main()
{	
	void update_segment_tree(ll a, ll b, ll k, ll l, ll r, ll index);
	void complete_lazy(ll,ll,ll);
	ll n,m;
	cin>>n>>m;

	// fill(numbers.begin(), numbers.begin()+n, 0);
	fill(segment_tree.begin(), segment_tree.begin()+5*n/2, mp(0,0));

	while(m--)
	{
		ll a,b,k;
		cin>>a>>b>>k;
		a--;
		b--;
		update_segment_tree(a,b,k,0,n-1,0);
	}

	complete_lazy(0,n-1,0);

	ll answer = (max_element(segment_tree.begin(),segment_tree.begin()+5*n/2))->second;
	cout<<answer<<"\n";

	// rep(i,2*n)
	// {
	// 	cout<<segment_tree[i].second<<" ";
	// }
	// cout<<"\n";
} 


void update_segment_tree(ll a, ll b, ll k, ll l, ll r, ll index)
{
	if((l >= a)&&(r <= b))
	{
		segment_tree[index].second += k;
		return;
	}
	else if((l > b)||(r < a))
	{
		return;
	}
	else
	{
		update_segment_tree(a,b,k,l,(l+r)/2,2*index+1);
		update_segment_tree(a,b,k,(l+r)/2+1,r,2*index+2);
		return;
	}
}

void complete_lazy(ll l,ll r, ll index)
{
	if(l == r)
	{
		return;
	}
	else
	{
		segment_tree[2*index+1].second += segment_tree[index].second;
		segment_tree[2*index+2].second += segment_tree[index].second;
		complete_lazy(l,(l+r)/2,2*index+1);
		complete_lazy((l+r)/2+1,r,2*index+2);
		return;
	}
}
