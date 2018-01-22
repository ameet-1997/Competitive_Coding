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

vi numbers(100000);


int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int n,k;
		cin>>n>>k;
		rep(i,n)
		{
			cin>>numbers[i];
		}

		sort(numbers.begin(), numbers.begin()+n);

		int answer = 0;

		for(int i=0;i<=3*100000;++i)
		{
			bool flag = binary_search(numbers.begin(), numbers.begin()+n, i);

			if(!flag&&(k<=0))
			{
				answer = i;
				break;
			}
			else if(!flag)
			{
				k--;
			}
		}

		cout<<answer<<endl;
	}
}