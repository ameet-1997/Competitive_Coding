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


int main()
{
	int p,x,y;
	cin>>p>>x>>y;

	vector<int> positions(30);

	vector< vector<int> > answers(475);

	for(int i=0;i<475;++i)
	{
		answers[i].resize(25);
	}

	for(int i=0;i<475;++i)
	{
		int temp = i;

		for(int j=0;j<25;++j)
		{
			temp = ((96*temp)+42)%475;
			answers[i][j] = temp+26;
		}
	}

	int minimum_successful_hacks = INT_MAX;

	for(int i=0;i<475;++i)
	{
		if(find(answers[i].begin(), answers[i].end(), p) != answers[i].end())
		{
			int current_mod = (x/50)%475;

			if(current_mod == i)
			{
				minimum_successful_hacks = min(minimum_successful_hacks, 0);
			}
			else
			{
				if(i > current_mod)
				{
					if(x - (475-i+current_mod)*50 >= y)
					{
						minimum_successful_hacks = 0;
					}
					else
					{
						minimum_successful_hacks = min(minimum_successful_hacks, (i+1-current_mod)/2);
					}
				}
				else
				{
					if(x - (current_mod - i)*50 >= y)
					{
						minimum_successful_hacks = 0;
					}
					else
					{
						minimum_successful_hacks = min(minimum_successful_hacks, (475-current_mod+i+1)/2);
					}
				}
			}
		}
	}

	cout<<minimum_successful_hacks<<"\n";
} 
