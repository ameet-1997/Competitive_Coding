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
	int gcd(int a, int b);
	pii extended_euclid(int a,int b);
	int a,b,d;

	cin>>a>>b>>d;

	int temp1 = max(a,b);
	int temp2 = min(a,b);
	a = temp1;
	b = temp2;

	if(d % gcd(a,b))
	{
		cout<<"-1\n";
		exit(0);
	}

	temp1 = gcd(a,b);
	a = a/temp1;
	b = b/temp1;
	d = d/temp1;

	if(a == b)
	{
		cout<<d/b<<"\n";
	}
	else
	{
		pii temp1 = extended_euclid(a,b);
		temp1.ff = temp1.ff*d;
		temp1.ss = temp1.ss*d;

		//cout<<temp1.ff<<" "<<temp1.ss<<"\n";

		if(temp1.ff < 0)
		{
			int check = temp1.ss/a;
			temp1.ss = temp1.ss - check*a;
			temp1.ff = temp1.ff + check*b;
			int answer = abs(temp1.ss) + abs(temp1.ff);
			temp1.ss = temp1.ss - a;
			temp1.ff = temp1.ff + b;
			answer = min(answer, abs(temp1.ff) + abs(temp1.ss));
			cout<<answer<<"\n";			
		}
		else
		{
			int check = (-temp1.ss)/a;
			temp1.ss = temp1.ss + check*a;
			temp1.ff = temp1.ff - check*b;
			int answer = abs(temp1.ss) + abs(temp1.ff);
			temp1.ss = temp1.ss + a;
			temp1.ff = temp1.ff - b;
			answer = min(answer, abs(temp1.ff) + abs(temp1.ss));
			cout<<answer<<"\n";			
		}
	}


}

int gcd(int a, int b)
{
	if(a%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a%b);
	}
}


pii extended_euclid(int a,int b)
{
	if(b == 0)
	{
		return mp(1,0);
	}
	else
	{
		pii temp = extended_euclid(b, a%b);

		return mp(temp.ss, temp.ff - temp.ss*(a/b));
	}
}