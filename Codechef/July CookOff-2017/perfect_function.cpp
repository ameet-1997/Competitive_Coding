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

vl squares(1000000);

int main()
{
	ll a,b;
	cin>>a>>b;

	// cout<<"Values are : "<<a<<" "<<b<<endl;
	ll answer = 0;

	for(ll i=0;i<1000000;++i)
	{
		squares[i] = (i+1)*(i+1);
	}

	// rep(i,10)
	// {
	// 	cout<<squares[i]<<" ";
	// }
	// cout<<endl;

	for(ll i=1;i<=a;++i)
	{	
		// cout<<"For "<<i<<" : ";
		// cout<<"value : "<<i*i+b;
		// ll value = 
		int index2 = (upper_bound(squares.begin(), squares.end(), i*i+b) - squares.begin());
		index2--;

		int index1 = (lower_bound(squares.begin(), squares.end(), i*i) - squares.begin());
		index1++;

		answer += (index2 - index1 + 1);
		// cout<<index1<<" : "<<index2<<endl;
	}

	cout<<answer<<endl;
} 
