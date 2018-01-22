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

	int correct = 0, wrong = 0;

	rep(i,len-1)
	{
		if((s[i] == 'V')&&(s[i+1] == 'K'))
		{
			correct++;
			i++;
		}
		else if((s[i] == 'K')&&(s[i+1] == 'K'))
		{
			wrong++;
		}
		else if((s[i] == 'V')&&(s[i+1] == 'V'))
		{
			if(i == len-2)
			{
				wrong++;
			}
			else if(s[i+2] != 'K')
			{
				wrong++;
			}
		}
	}

	if(wrong)
	{
		cout<<correct+1<<endl;
	}
	else
	{
		cout<<correct<<endl;
	}
} 
