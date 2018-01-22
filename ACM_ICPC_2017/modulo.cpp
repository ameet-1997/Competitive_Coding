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
	std::ios::sync_with_stdio(false);
	ll test;
	cin>>test;

	while(test--){
		ll n;
		cin>>n;
		vl a(n);
		vl b(n);

		rep(i,n){
			cin>>a[i];
		}

		rep(i,n){
			cin>>b[i];
		}

		vll modu(n);

		rep(i,n){
			modu[i].first = a[i]%b[i];
			modu[i].second = b[i];
		}

		sort(modu.begin(), modu.end());

		vl p1(n);
		p1[0] = modu[0].first;
		// cout<<p1[0]<<" ";
		for(ll i=1;i<n;++i){
			p1[i] = p1[i-1]+modu[i].first;
			// cout<<p1[i]<<" ";
		}
		// cout<<endl;

		vl p12(n);
		p12[0] = modu[0].second;
		// cout<<p12[0]<<" ";
		for(ll i=1;i<n;++i){
			p12[i] = p12[i-1]+modu[i].second;
			// cout<<p12[i]<<" ";
		}
		// cout<<endl;

		ll answer = LONG_LONG_MAX;
		// cout<<answer<<endl;

		ll min_bi = *min_element(b.begin(), b.end());

		ll a_sum = 0;
		rep(i,n){
			a_sum += modu[i].first;
		}


		int i=0;
		rep(i,n){
			// ll temp = modu[i];
			// ll temp = (i+1)*modu[i].first - p1[i] + (p1[n-1]-p1[i]) - (n-i-1)*modu[i].first+p12[n-1]-p12[i];
			// ll temp = n*modu[i].first -p1[n-1]+p12[n-1]-p12[i];
			ll temp = n*modu[i].first - a_sum+p12[n-1]-p12[i];
			// cout<<"Temp is: "<<temp<<endl;

			if(modu[i].first < min_bi){
				answer = min(answer, temp);
			}
			else{
				break;
			}	
		}
		cout<<answer<<endl;
	}
}