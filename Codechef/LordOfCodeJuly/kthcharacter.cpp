#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
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

vector<ll> power_of_two(100);

int main()
{	
	ll initial = 1;
	for(int i=0;i<=60;++i)
	{
		power_of_two[i] = initial - 1;
		initial *= 2;
	}

	// for(int i=0;i<60;++i)
	// {
	// 	cout<<power_of_two[i]<<" ";
	// }
	// cout<<"\n";
	
	int test;
	cin>>test;
	
	while(test--)
	{
		ll k;
		cin>>k;

		bool flag = false;
		int current = lower_bound(power_of_two.begin(), power_of_two.begin()+61, k) - power_of_two.begin();

		// cout<<"Current is : "<<current<<"\n";
		
		while(k > 0)
		{
			// current = upper_bound(power_of_two.begin(), power_of_two.end(), k) - power_of_two.begin();

			if(k == (power_of_two[current-1]+1))
			{
				break;
			}
			else if(k > (power_of_two[current-1]+1))
			{
				flag = !flag;
				k = k - (power_of_two[current-1]+1);
				k = power_of_two[current-1] + 1 - k;
			}

			// cout<<"The value of k is : "<<k<<"\n";
			
			current--;
		}

		if(flag)
		{
			cout<<"c\n";
		}
		else
		{
			cout<<"a\n";
		}
		
	}
}