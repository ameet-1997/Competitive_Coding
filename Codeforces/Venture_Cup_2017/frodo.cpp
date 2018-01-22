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



int main()
{	
	int quadratic(int a,int b, int c);

	int n,m,k;
	cin>>n>>m>>k;

	int al1,bl1,cl1;
	int al2,bl2,cl2;
	int ar1,br1,cr1;
	int ar2,br2,cr2;

	al1 = 1;
	bl1 = -1;
	cl1 = 2*k;

	al2 = 0;
	bl2 = 2*k;
	cl2 = -k*k + k;

	ar1 = 1;
	br1 = -1;
	cr1 = 2*n - 2*k + 2;

	ar2 = 0;
	br2 = 2*n - 2*k + 2;
	cr2 = (n-k+1)*(k-n);

	int final = 0;

	int temp;

	temp = quadratic(al1+ar1,bl1+br1-2,cl1+cr1-2*m);

	if( (temp > 0)&&(temp < k)&&(temp<n-k))
	{
		if(final < temp)
		{
			final = temp;
		}
	}

	temp = quadratic(al1+ar2,bl1+br2-2,cl1+cr2-2*m);

	if( (temp > 0)&&(temp < k)&&(temp>=n-k))
	{
		if(final < temp)
		{
			final = temp;
		}
	}

	temp = quadratic(al1+ar1,bl1+br1-2,cl1+cr1-2*m);

	if( (temp > 0)&&(temp >= k)&&(temp<n-k))
	{
		if(final < temp)
		{
			final = temp;
		}
	}

	temp = (2*m-(cl2+cr2))/(bl2+br2-2);

	if((temp>=k)&&(temp >= (n-k)))
	{
		if(final < temp)
		{
			final = temp;
		}		
	}

	cout<<final<<"\n";
} 


int quadratic(int a,int b, int c)
{
	int discriminant = b*b - 4*a*c;

	double ans1 = sqrt(discriminant);

	return (int)((-b+ans1)/(2*a));
}