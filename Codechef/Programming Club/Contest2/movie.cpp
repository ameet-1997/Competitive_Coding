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
		map<int,int> heroes;
		int n,m;
		cin>>n>>m;
		rep(i,m)
		{
			int temp;
			cin>>temp;

			if(heroes.find(temp) == heroes.end())
			{
				heroes[temp] = 1;
			}
			else
			{
				heroes[temp] += 1;
			}
		}

		auto it = heroes.begin();
		int answer = 0;
		int final_answer = -1;

		while(it != heroes.end())
		{
			if((it->second) >= answer)
			{
				answer = it->second;
				final_answer = it->first;
			}
			it++;
		}

		cout<<final_answer<<"\n";
	}
} 
