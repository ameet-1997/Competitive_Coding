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
	string s;
	cin>>s;

	int len = s.length();
	int x=0, y=0; 
	if(len%2)
	{
		cout<<"-1\n";
	}
	else
	{
		rep(i,len)
		{
			switch(s[i])
			{
				case 'L':{
					x--;
					break;
				}
				case 'R':{
					x++;
					break;
				}
				case 'U':{
					y++;
					break;
				}
				case 'D':{
					y--;
					break;
				}
			}
		}

		x = abs(x);
		y = abs(y);

		if(x%2 == 0)
		{
			cout<<(x+y)/2<<"\n";
		}
		else
		{
			cout<<x/2+y/2+1<<"\n";
		}
	}
} 
