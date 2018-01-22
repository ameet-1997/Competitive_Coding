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
	vi candies(n);

	rep(i,n)
	{
		cin>>candies[i];
	}

	if(n*8 < k)
	{
		cout<<"-1\n";
	}
	else
	{
		ll given = 0;
		bool flag = false;

		ll total = 0;
		int counter = 0;
		rep(i,n)
		{	
			counter++;
			total += candies[i];
			if(total > 8)
			{
				given += 8;
				total -= 8;
			}
			else
			{
				given += total;
				total = 0;
			}

			if(given >= k)
			{	
				flag = true;
				break;
			}
		}

		if(flag)
		{
			cout<<counter<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}
	}
} 
