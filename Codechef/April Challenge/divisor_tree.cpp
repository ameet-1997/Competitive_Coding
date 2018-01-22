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

#define sieve_max 1000001

//std::ios::sync_with_stdio(false);

vector<int> sieve_array(sieve_max+1); 	// Sieve is made to contain the maximum prime that divides the number
vector< vector<int> >list_of_primes(sieve_max+1);
vector<int> answer(1000000);

int main()
{
	void build_sieve();
	build_sieve();
	//fill(answer.begin(), answer.end(), 0);
	
	long long a,b;
	cin>>a>>b;


} 


void build_sieve(void)
{
	fill(sieve_array.begin(), sieve_array.end(),0);

	for(int i=2;i<=sieve_max;++i)
	{
		if(sieve_array[i] == 0)
		{
			int current = 2*i;

			while(current <= sieve_max)
			{
				sieve_array[current] = i;
				list_of_primes[current].push_back(i);
				current+=i;					// Essentially performing k*i
			}
		}
	}

}


	/*for(int i=0;i<211;++i)		// For checking the sieve function
	{
		//cout<<sieve_array[i]<<" ";

		vector<int>::iterator it = list_of_primes[i].begin();

		if(it == list_of_primes[i].end())
		{
			cout<<"None\n";
		}
		else
		{
			while( it != list_of_primes[i].end() )
			{
				cout<<*it<<" ";
				it++;
			}
			cout<<"\n";
		}
	}
	cout<<"\n";*/

	/*long long length_of_adjacency_list = 0;	// For checking the number of entries to be stored in the list_of_primes vector

	for(int i=2;i<sieve_max;++i)
	{
		if(sieve_array[i] == 0)
		{
			length_of_adjacency_list+=sieve_max/i;
		}
	}

	cout<<length_of_adjacency_list<<"\n";*/

