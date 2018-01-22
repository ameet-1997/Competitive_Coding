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
	// ll answer = 0;
	ll x,y;
	cin>>x>>y;

	// if(x >= y)
	// {
	// 	ll gc = __gcd(x,y);
	// 	answer = y/gc;
	// }
	// else
	// {	
	// 	ll gc = __gcd(x,y);
	// 	ll till = y/x*x;
	// 	answer = (y-till)/gc + (y-x)/x + 1;
	// }

	ll gcd1, gcd2;
	ll answer = 0;

	while(y != 0)
	{
		ll gc = __gcd(x,y);
		ll temp1 = x/gc;
		ll check;
		ll temp2 = check = y/gc;

		while(temp2 > 0)
		{
			if(__gcd(x,y) != 1)
			{
				answer += (check - temp2);
				break;
			}
			temp2--;
		}

		x /=gc;
		y = temp2;
	}

	cout<<answer<<endl;
} 
