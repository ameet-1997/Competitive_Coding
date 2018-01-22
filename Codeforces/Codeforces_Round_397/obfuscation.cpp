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
	string input;
	cin>>input;
	vi alphabet(26);

	fill(alphabet.begin(),alphabet.end(),0);

	int len = input.length();

	for(int i=0;i<len;++i)
	{
		alphabet[input[i]-'a']++;
	}

	for(int i=1;i<26;++i)
	{
		if((alphabet[i] > 0)&&(alphabet[i-1] == 0))
		{
			cout<<"NO\n";
			return 0;
		}
	}

	int current = -1;

	for(int i=0;i<len;++i)
	{
		if(input[i]-'a' == current + 1)
		{
			current++;
		}
		else if(input[i]-'a' > current+1)
		{
			cout<<"NO\n";
			return 0;
		}
	}


	cout<<"YES\n";
} 
