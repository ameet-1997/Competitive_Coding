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
//setfill - cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
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
	int n;
	cin>>n;

	string s;

	cin>>s;


	int answer_robot = 0;

	int dist_h = 0;
	int dist_v = 0;

	int temp_h = 0,temp_v = 0;

	for(int i=0;i<n;++i)
	{	
		temp_h = dist_h;
		temp_v = dist_v;
		if(s[i] == 'L')
		{
			dist_h = dist_h-1;
		}

		if(s[i] == 'R')
		{
			dist_h = dist_h+1;
		}

		if(s[i] == 'D')
		{
			dist_v = dist_v-1;
		}

		if(s[i] == 'U')
		{
			dist_v = dist_v+1;
		}

		if((abs(dist_h) < abs(temp_h))||(abs(dist_v) < abs(temp_v)))
		{
			answer_robot++;

			switch(s[i])
			{
				case 'L' :{
					dist_h = -1;
					dist_v = 0;
					break;
				}

				case 'R' :{
					dist_h = 1;
					dist_v = 0;
					break;
				}

				case 'D' :{
					dist_h = 0;
					dist_v = -1;
					break;
				}

				case 'U' :{
					dist_h = 0;
					dist_v = 1;
					break;
				}
			}
		}
	}


	cout<<answer_robot+1<<"\n";
} 
