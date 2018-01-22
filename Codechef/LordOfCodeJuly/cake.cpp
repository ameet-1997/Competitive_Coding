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

vi primes(10000);
vi numbers(100000);
vi prime_index(1000);

int main()
{	
	void sieve(int);

	sieve(1000);
	map<int,int> prime_map;

	int counter = 0;

	rep(i,1000)
	{
		if(primes[i] == 0)
		{
			prime_map[i] = counter;
			counter++;
		}
	}

	int test;
	cin>>test;

	while(test--)
	{
		int n;
		rep(i,n)
		{
			cin>>numbers[i];
		}

		ll current_product = 1;
		int index = 0;

		while(index < n)
		{	
			int current = numbers[index];
			while(1)
			{
				if(primes[current] == 0)
				{
					
				}
			}
		}

	}
}


void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(primes[i] == 0)
		{
			int current = 2*i;

			while(current <= n)
			{
				primes[current] = i;
				current += i;
			}
		}
	}
}