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
		int n;
		cin>>n;
		vi numbers(n);

		rep(i,n)
		{
			cin>>numbers[i];
		}

		int current = n;

		while(current > 1)
		{
			int counter = 0;

			for(int i=0;i<current-1;i+=2)
			{
				numbers[counter] = numbers[i]^numbers[i+1];
				counter++;
			}

			if(current%2)
			{
				numbers[counter] = numbers[current-1];
				current = current/2+1;
			}
			else
			{
				current /= 2;
			}
		}

		cout<<numbers[0]<<"\n";

	}
}
