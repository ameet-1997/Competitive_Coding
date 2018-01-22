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

int main()
{	
	int test;
	cin>>test;

	vi numbers(100000);
	vi subarray(100000);

	while(test--)
	{
		int n;
		int answer2 = 0;
		int flag = 0;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>numbers[i];
			if(numbers[i] > 0)
			{
				answer2+=numbers[i];
				flag = 1;
			}
		}

		subarray[n-1] = numbers[n-1];

		for(int i = n-2;i >= 0;--i)
		{
			if(subarray[i+1] > 0)
			{
				subarray[i] = subarray[i+1] + numbers[i];
			}
			else
			{
				subarray[i] = numbers[i];
			}
		}

		int answer1 = -1000*1000*1000-1;

		for(int i=0;i<n;++i)
		{
			if(subarray[i] > answer1)
			{
				answer1 = subarray[i];
			}

		}	

		if(flag == 0)
		{
			answer2 = answer1;
		}

		cout<<answer1<<" "<<answer2<<"\n";
	}

} 
