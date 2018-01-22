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

vi blocks(100000);
vi hl(100000);
vi hr(100000);
int main()
{
	int test;
	cin>>test;

	while(test--)
	{	
		ll total_blocks = 0;
		int n;
		cin>>n;
		rep(i,n)
		{
			cin>>blocks[i];
			total_blocks += blocks[i];
		}

		hl[0] = 1;
		hr[n-1] = 1;

		for(int i=1;i<n;++i)
		{
			hl[i] = min(hl[i-1]+1, blocks[i]);
		}

		for(int i=n-2;i>=0;--i)
		{
			hr[i] = min(hr[i+1]+1,blocks[i]);
		}

		for(int i=0;i<n;++i)
		{
			blocks[i] = min(hl[i],hr[i]);
		}

		int answer = *(max_element(blocks.begin(),blocks.begin()+n));
		ll final_answer = total_blocks - answer*answer;
		cout<<final_answer<<endl;



		
	}
} 
