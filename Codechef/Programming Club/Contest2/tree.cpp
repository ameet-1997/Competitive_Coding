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
		vector<ll> numbers(3);
		rep(i,3)
		{
			cin>>numbers[i];
		}

		vector<ll> level(3);

		rep(i,3)
		{
			level[i] = log2(numbers[i]);
		}

		// cout<<"Levels are : \n";
		// rep(i,3)
		// {
		// 	cout<<level[i]<<" ";
		// }
		// cout<<"\n";

		// For q

		ll l1 = level[0];
		ll l2 = level[1];
		ll n1 = numbers[0];
		ll n2 = numbers[1];

		vector<ll> dist(2);

		if(l1 > l2)
		{
			while(l1 != l2)
			{
				n1 /= 2;
				l1--;
			}
		}
		else if(l1 < l2)
		{
			while(l1 != l2)
			{
				n2 /= 2;
				l2--;
			}			
		}

		while(n1 != n2)
		{
			n1 /= 2;
			n2 /= 2;
			l1--;
		}

		dist[0] = level[0] + level[1] - 2*l1;




		l1 = level[0];
		l2 = level[2];
		n1 = numbers[0];
		n2 = numbers[2];

		if(l1 > l2)
		{
			while(l1 != l2)
			{
				n1 /= 2;
				l1--;
			}
		}
		else if(l1 < l2)
		{
			while(l1 != l2)
			{
				n2 /= 2;
				l2--;
			}			
		}

		while(n1 != n2)
		{
			n1 /= 2;
			n2 /= 2;
			l1--;
		}

		dist[1] = level[0] + level[2] - 2*l1;

		// cout<<"Distances are : "<<dist[0]<<" "<<dist[1]<<"\n";

		if(dist[0] < dist[1])
		{
			cout<<"FIRST\n";
		}
		else if(dist[0] == dist[1])
		{
			cout<<"BOTH\n";
		}
		else
		{
			cout<<"SECOND\n";
		}


	}
} 
