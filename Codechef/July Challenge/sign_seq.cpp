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

vi less_than(100000);
vi greater_than(100000);

int main() 
{
	int test;
	cin>>test;

	while(test--)
	{
		string s;
		cin>>s;

		int n = s.length();
		fill(less_than.begin(), less_than.begin()+n+1,0);
		fill(greater_than.begin(), greater_than.begin()+n+1,0);

		int counter = 0;

		less_than[0] = 0;
		rep(i,n)
		{	
			if(s[i] == '<')
			{
				counter++;
			}
			else if(s[i] == '>')
			{
				counter = 0;
			}

			less_than[i+1] = counter;
		}



		counter = 0;

		greater_than[n] = 0;
		for(int i=n-1;i>=0;--i)
		{	
			if(s[i] == '>')
			{
				counter++;
			}
			else if(s[i] == '<')
			{
				counter = 0;
			}

			greater_than[i] = counter;
		}

		int answer = 0;

		rep(i,n+1)
		{
			answer = max(answer, max(less_than[i],greater_than[i])+1);
		}

		cout<<answer<<"\n";
	}
}
