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

vl spaghetti(1000000);

int main()
{	
	bool possible(int a,int b,int c);
	ll n,l,r;
	cin>>n>>l>>r;

	rep(i,n)
	{
		cin>>spaghetti[i];
	}

	sort(spaghetti.begin(),spaghetti.begin()+n);

	ll right,left = 1000000000000000000;


	if(spaghetti[n-2] + spaghetti[n-1] - 1 < l)
	{
		cout<<"0\n";
		exit(0);
	}
	else
	{	
		right = min((ll)r,spaghetti[n-2] + spaghetti[n-1] - 1);
	}

	bool flag = false;

	f(i,1,n)
	{
		left = min((ll)left,spaghetti[i]-spaghetti[i-1]+1);

		if(left > spaghetti[i]-spaghetti[i-1]+1)
		{
			left = spaghetti[i]-spaghetti[i-1]+1;
		}

		if((!flag)&&(possible(l,spaghetti[i],spaghetti[i-1])))
		{
			flag = true;
		}
	}

	if((left < l)&&(flag))
	{
		left = l;
	}
	/*else if(left < l)
	{	
		left = 1000000000000000000;
		f(i,1,n)
		{
			left = min((ll)left, spaghetti[i]+spaghetti[i-1]+1);
		}
	}*/

	cout<<left<<" "<<right<<"\n";
	cout<<right-left+1<<"\n";
} 


bool possible(int a,int b,int c)
{
	if((a+b > c)&&(b+c > a)&&(c+a >b))
	{
		return true;
	}
	else
	{
		return false;
	}
}
