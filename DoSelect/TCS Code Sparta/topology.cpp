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

vi degree(1000000);

int main()
{
	int n,m;

	cin>>n;
	cin>>m;


	fill(degree.begin(), degree.begin()+n,0);

	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;

		degree[x-1]++;
		degree[y-1]++;
	}

	vector<int> answer(3);

	int counter = 0;
	fill(answer.begin(), answer.end(),0);

	for(int i=0;i<n;++i)
	{	
		if(degree[i] == 0)
		{
			cout<<"unknown topology\n";
			return 0;
		}
		else if(degree[i] <= 2)
		{
			answer[degree[i]-1]++;	
		}
		else
		{
			if(counter == 0)
			{
				answer[2] = degree[i];
			}
			else
			{
				cout<<"unknown topology\n";
				return 0;				
			}
		}
		
	}

	if((answer[0] == 2)&&(answer[1] == n-2))
	{
		cout<<"line topology\n";
	}
	else if(answer[1] == n)
	{
		cout<<"ring topology\n";
	}
	else if((answer[0] == n-1)&&(answer[1] == 0)&&(answer[2] == n-1))
	{
		cout<<"star topology\n";
	}
	else
	{
		cout<<"unknown topology\n";
	}

	return 0;
} 
