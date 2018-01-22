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
		string p,q;
		cin>>p>>q;

		bool flag = true;
		bool answer = true;

		int len = p.length();

		map<char,char> mapping;
		map<char,char> inverse_mapping;
		map<char,int> alphabet;

		rep(i,len)
		{	
			alphabet[p[i]] = 1;
			if(p[i]!=q[i])
			{
				flag = false;
			}

			if(mapping.find(p[i]) == mapping.end())
			{
				if(inverse_mapping.find(q[i]) != inverse_mapping.end())
				{
					answer = false;
					break;
				}
				else
				{
					mapping[p[i]] = q[i];
					inverse_mapping[q[i]] = p[i];
				}
			}
			else
			{
				if(q[i] != mapping[p[i]])
				{
					answer = false;
					break;
				}
			}
		}

		if(flag)
		{
			cout<<"YES\n";
		}
		else
		{
			if(answer&&(alphabet.size() < 26))
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}
}