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

ll c[100001];
char a[100002];

int main()
{
	int test;
	cin>>test;
	
	for(int zz=0;zz<test;++zz)
	{
		int n;
		cin>>n;
		
		cin>>a;
		
		long long answer = 0;
		
		cin>>c[0];
		for(int i=1;i<n;++i)
		{
			cin>>c[i];
			answer = answer + c[i]-c[i-1];
		}

		
		int left = -1;
		for(int i=0;i<n;++i)
		{
			if(a[i] == '1')
			{
				left = i;
				break;
			}
		}
	
		for(int i=left;i<n;++i)
		{
			if(a[i] == '1')
			{	
				//cout<<"I is : "<<i<<"\n";
				int max = 0;
				a[i] = 0;
				while((a[i]!='1')&&(i<n))
				{
					if((c[i+1] - c[i]) > max)
					{
						max = c[i+1] - c[i];
					}
					i++;
				}
				
				if(i == n)
				{
					continue;
				}
				else
				{
					answer = answer - max;
				}
				i--;
				
			}
		
		}
		
		
		cout<<answer<<"\n";
		
		
		
	}
}
