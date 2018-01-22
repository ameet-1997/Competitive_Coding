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
	int n,k;
	cin>>n>>k;

	vi numbers1(100000);
	vi numbers2(100000);

	rep(i,n)
	{
		cin>>numbers1[i];
	}

	rep(i,n)
	{
		cin>>numbers2[i];
	}

	int maximum = 0;
	int maximum_index = 0;

	rep(i,n)
	{
		if(abs(numbers2[i]) > maximum)
		{
			maximum = abs(numbers2[i]);
			maximum_index = i;
		}
	}

	if(numbers2[maximum_index] >= 0)
	{
		numbers1[maximum_index] -= 2*k;
	}
	else
	{
		numbers1[maximum_index] += 2*k;
	}

	long long answer = 0;

	rep(i,n)
	{
		answer += numbers1[i]*numbers2[i];
	}

	cout<<answer;

	return 0;

} 
