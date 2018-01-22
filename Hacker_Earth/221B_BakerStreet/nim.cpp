 
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
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
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
 

vi heaps(1000000);

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int n;
		cin>>n;
		int answer = 0;

		for(int i=0;i<n;++i)
		{
			cin>>heaps[i];
		}

		int counter = 0;		
		for(int i=0;i<n;++i)
		{	
			int check = 0;
			for(int j=0;j<n;++j)
			{
				if(j!=i)
				{
					check = check^heaps[j];
				}
			}

			if(heaps[i] > check)
			{
				answer++;
			}

		}

		cout<<answer<<"\n";
	}
} 

long long nim_sum(int n)
{
	int answer = heaps[0];

	for(int i=1;i<n;++i)
	{
		answer = answer^heaps[i];
	}

	return answer;
}