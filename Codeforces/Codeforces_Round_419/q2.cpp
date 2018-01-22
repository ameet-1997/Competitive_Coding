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

vii recipes;
// vi recipes_end(200000);

int main()
{
	int n,k,q;
	cin>>n>>k>>q;

	rep(i,n)
	{	
		int x,y;
		cin>>x;
		cin>>y;
		recipes.push_back(mp(x,0));
		recipes.push_back(mp(y,1));
	}

	sort(recipes.begin(), recipes.end());

	while(q--)
	{
		pair<int,int> question;
		cin>>question.first>>question.second;

		int end_counter = 0;
		int count = 0;

		rep(i,n)
		{
			while(recipes[end_counter].second < recipes[i].first)
			{
				end_counter++;
				count--;
			}
			count++;

		}
	}




} 
