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
	vi answer(1001);
	vi number_of_digits(1001);

	answer[0] = 6;
	int number_to_add = 22;

	rep(i,1000)
	{
		answer[i+1] = answer[i] + number_to_add;
		number_to_add += 16;
		number_of_digits[i] = log10(answer[i]) + 1;
	}

	int n;
	cin>>n;

	int cur = 0;

	for(int i=0;i<n;++i)
	{	
		rep(k,n-1-i)
		{
			cout<<" ";
		}
		for(int j=0;j<=i;++j)
		{
			rep(k,5- number_of_digits[cur])
			{
				cout<<"0";
			}
			cout<<answer[cur]<<" ";

			cur++;
		}

		if(i < n-1)
		{
			cout<<"\n";
		}
		
	}
} 
