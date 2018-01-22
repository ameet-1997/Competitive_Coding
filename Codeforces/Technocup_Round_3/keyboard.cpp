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

int a[26] = {-1};
 
int main()
{	
	for(int i=0;i<26;++i)
	{
		a[i] = -1;
	}
	string favorite,result;
	cin>>favorite;
	cin>>result;

	int number = 0;

	for(int i=0;i<favorite.length();++i)
	{
		if(favorite[i] == result[i])
		{
			a[favorite[i]-'a'] = -1;
		}
		else
		{	
			if((a[favorite[i]-'a'] == -1)&&(a[result[i]-'a'] == -1))
			{
				a[favorite[i]-'a'] = result[i]-'a';
				a[result[i]-'a'] = favorite[i]-'a';
				number++;

			}
			else if((a[favorite[i]-'a']!=result[i]-'a')||(a[result[i]-'a']!=favorite[i]-'a'))
			{
				cout<<"-1\n";
				return 0;
			}


		}
	}

	cout<<number<<"\n";
	for(int i=0;i<26;++i)
	{
		if(a[i] > 0)
		{
			cout<<(char)(i+'a')<<" "<<(char)(a[i] + 'a')<<"\n";
			a[a[i]] = -1;
		}
	}
} 
