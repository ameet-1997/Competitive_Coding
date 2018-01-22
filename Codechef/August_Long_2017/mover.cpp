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
		ll n,d;
		cin>>n>>d;

		vl numbers(n);
		ll total = 0;
		ll answer = 0;
		rep(i,n)
		{
			cin>>numbers[i];
			total += numbers[i];
		}

		ll check = total/n;

		if(total%n)
		{
			cout<<"-1\n";
		}
		else
		{
			for(ll i=0;i+d<n;++i)
			{	
				ll temp = numbers[i]-check;
				answer += abs(temp);
				numbers[i] = check;
				numbers[i+d] = numbers[i+d] + temp;
			}

			bool flag = true;

			// rep(i,n)
			// {
			// 	cout<<numbers[i]<<" ";
			// }
			// cout<<endl;

			rep(i,n)
			{
				if(numbers[i] != check)
				{
					flag = false;
					break;
				}
			}

			if(flag)
			{
				cout<<answer<<endl;
			}
			else
			{
				cout<<"-1\n";
			}
		}



	}
} 
