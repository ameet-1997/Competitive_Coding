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
	int test;
	cin>>test;

	while(test--)
	{
		string s;
		string t;
		cin>>s>>t;

		vi count_a(26);
		vi count_b(26);
		fill(count_a.begin(), count_a.end(), 0);
		fill(count_b.begin(), count_b.end(), 0);

		int len = s.length();
		rep(i,len)
		{
			count_a[s[i]-'a']++;
			count_b[t[i]-'a']++;
		}

		bool flag = false;
		rep(i,26)
		{
			if((count_a[i] > 0)&&(count_b[i] == 0))
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			cout<<"B\n";
		}
		else
		{
			flag = false;
			rep(i,26)
			{
				if((count_a[i] > 1)&&(count_b[i] == 0))
				{
					flag = true;
					break;
				}				
			}
			if(flag)
			{
				cout<<"A\n";
			}
			else
			{
				flag = false;
				rep(i,26)
				{
					if((count_b[i] > 0)&&(count_a[i] == 0))
					{
						flag = true;
						break;
					}
				}
				if(flag)
				{
					cout<<"B\n";
				}
				else
				{
					cout<<"A\n";
				}
			}

		}
	}
}