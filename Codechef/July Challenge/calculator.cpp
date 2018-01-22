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
	ll test;
	cin>>test;

	while(test--)
	{
		ll n,b;
		cin>>n>>b;

		ll ans = n/2;

		ll rem = (n-ans)%b;

		ll ans1 = ans+rem;
		ll ans2 = ans - (b-rem);

		ll candid1 = max(((n-ans1)/b)*ans1,(ll)0);
		ll candid2 = max(((n-ans2)/b)*ans2,(ll)0);

		ll final_answer = max(candid1, candid2);

		if(rem == 0)
		{
			ll ans3 = ans+b;
			if(ans3 <= n)
			{
				final_answer = max(final_answer, ((n-ans3)/b)*ans3);
			}
		}
		cout<<final_answer<<"\n";
	}
}
