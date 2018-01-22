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
			a[i] = a[i]%b[i];
		}

		ll max_possible = *min_element(b.begin(), b.end())-1;
		ll min_sum = 0;

		rep(i,n){
			if(a[i] > max_possible){
				min_sum += (b[i]-a[i]);
				a[i] = 0;
			}
		}

		vl temp(a);
		sort(temp.begin(), temp.end());
		ll answer = temp[n/2];

		rep(i,n){
			min_sum += abs(answer-a[i]);
		}

		cout<<min_sum<<endl;
	}	
} 
