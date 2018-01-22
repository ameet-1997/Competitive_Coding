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
	int n,m;
	cin>>n>>m;

	vector< vector<int> > flag(n);

	rep(i,n)
	{
		flag[i].resize(m);
	}

	bool f = false;

	rep(i,n)
	{
		rep(j,m)
		{
			char c;
			cin>>c;
			switch(c)
			{
				case 'R':{
					flag[i][j] = 0;
					break;
				}
				case 'G':{
					flag[i][j] = 1;
					break;
				}
				case 'B':{
					flag[i][j] = 2;
					break;
				}
			}
		}
	}

	if(n%3 == 0)
	{	
		vi color(3);
		color[0] = flag[0][0];
		color[1] = flag[n/3][0];
		color[2] = flag[2*n/3][0];
		bool flag1 = true;

		rep(i,n)
		{
			rep(j,m)
			{
				if(flag[i][j] != color[i*3/n])
				{
					flag1 = false;
					break;
				}
			}
			if(!flag1)
			{
				break;
			}
		}

		f = f||flag1;
	}
	else if(m%3 == 0)
	{
		vi color(3);
		color[0] = flag[0][0];
		color[1] = flag[0][m/3];
		color[2] = flag[0][2*m/3];
		bool flag1 = true;

		rep(i,n)
		{
			rep(j,m)
			{
				if(flag[i][j] != color[j*3/m])
				{
					flag1 = false;
					break;
				}
			}
			if(!flag1)
			{
				break;
			}
		}

		f = f||flag1;
	}

	if(f)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
} 
