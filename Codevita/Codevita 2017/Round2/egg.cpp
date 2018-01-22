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
	int m,x;
	cin>>m>>x;

	vii eggs(m);
	// vi final(m);
	viii final(m);

	ll total = 0;

	rep(i,m)
	{
		cin>>eggs[i].first;
		total += eggs[i].ff;
		eggs[i].first = -eggs[i].first;
		eggs[i].second = i;
		final[i].ff = -eggs[i].ff;
		final[i].ss.ff = 0;
		final[i].ss.ss = -eggs[i].ff;
	}

	sort(eggs.begin(), eggs.end());

	int x1 = x;


	rep(i,m)
	{
		if(x <= 0)
		{
			break;
		}

		if(x >= -eggs[i].first)
		{
			final[eggs[i].ss].ff = -eggs[i].ff;
			final[eggs[i].ss].ss.ff = -eggs[i].ff;
			final[eggs[i].ss].ss.ss = 0;
			x += eggs[i].ff;
		}
		else
		{
			final[eggs[i].ss].ff = -eggs[i].ff;
			final[eggs[i].ss].ss.ff = x;
			final[eggs[i].ss].ss.ss = -eggs[i].ff - x;
			x = 0;

		}
	}

	ll answer;

	if(x1 >= total)
	{
		final[eggs[m-1].ss].ff = -eggs[m-1].ff;
		final[eggs[m-1].ss].ss.ff -= 1;
		final[eggs[m-1].ss].ss.ss = 1;
		answer = total-1;

		// final[eggs[m-1].ss].ff = -eggs[m-1].ff;
		// final[m-1].ss.ff = final[m-1].ff -1;
		// final[m-1].ss.ss = 1;
		// answer = total-1;
	}
	else
	{
		answer = x1;
	}

	if(x1 >= total)
	{
		cout<<"Sorry, we can only supply "<<answer<<" eggs"<<endl;
	}
	else
	{
		cout<<"Thank you, your order for "<<answer<<" eggs is accepted"<<endl;
	}

	rep(i,m)
	{
		cout<<final[i].ff<<" "<<final[i].ss.ff<<" "<<final[i].ss.ss<<"\n";
	}

} 
