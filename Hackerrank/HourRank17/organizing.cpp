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

int matrix[200][200];

int main()
{
	int q;

	cin>>q;

	while(q--)
	{
		int n;
		cin>>n;

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				cin>>matrix[i][j];
			}
		}


		vi numbers(1000);
		fill(numbers.begin(),numbers.begin()+n,0);

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				numbers[i]+=matrix[i][j];
			}
		}

		vi balls(1000);
		fill(balls.begin(),balls.begin()+n,0);

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				balls[i]+=matrix[j][i];
			}
		}

		sort(numbers.begin(),numbers.begin()+n);
		sort(balls.begin(),balls.begin()+n);


		int flag = 0;

		for(int i=0;i<n;++i)
		{
			if(numbers[i] != balls[i])
			{
				flag = 1;
				break;
			}
		}

		if(flag == 0)
		{
			cout<<"Possible\n";
		}
		else
		{
			cout<<"Impossible\n";
		}
	}
} 
