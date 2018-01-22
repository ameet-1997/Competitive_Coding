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
	int x,y;
	cin>>x>>y;

	int total = 0;
	int side = 2*y-1;

	if(2*y-1 >= x)
	{
		side = x;
	}
	else
	{
		total++;
	}

	int a = x - side + 1;
	total += 2;

	if((x-y) % (2*(side-1)) == 0)
	{
		total += x/(2*(side-1));
	}
	else
	{
		total = total + x/(2*(side-1)) + 1;
	}

	if(a > y)
	{
		if((a-y) % (2*(side-1)) == 0)
		{
			total += a/(2*(side-1));
		}
		else
		{
			total = total + a/(2*(side-1)) + 1;
		}		
	}

	cout<<total<<"\n";

} 
