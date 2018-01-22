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

vector<ll> numbers(100000);
vector<ll> dp_array_1(100000);
vector<ll> dp_array_2(100000);
int main()
{
	int test;
	cin>>test;

	while(test--)
	{	
		int n;
		cin>>n;
		fill(dp_array_1.begin(), dp_array_1.begin()+n,1);
		fill(dp_array_2.begin(), dp_array_2.begin()+n,0);

		rep(i,n)
		{
			cin>>numbers[i];
			if(i>0)
			{
				dp_array_1[i] = (dp_array_1[i-1]*numbers[i])%mod;
			}
		}

		dp_array_2[n-1] = numbers[n-1];
		for(int i=n-1;i>=0;--i)
		{

		}
	}
} 


ll power_of_2(int i)
{
	if(i == 0)
	{
		return 1;
	}
	else
	{
		if(i%2 == 1)
		{
			ll answer = power_of_2(i/2);
			return answer*answer*2;
		}
		else
		{
			ll answer = power_of_2(i/2);
			return answer*answer;
		}
	}
}