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

ll x;
long long a,b,c;

int main()
{
	double newton_raphson(double guess,int left,int right);
	double equation(double n);
	double derivative(double n);
	long long srch(long long x,int,int);
	a = 10000;
	b = 50000;
	c = 100000000000000;

	int test;
	cin>>test;

	while(test--)
	{
		
		cin>>x;

		if(x > 104000000000000)
		{
			cout<<srch(x,-10000,50000)<<"\n";
		}
		else
		{
			cout<<"-20000\n";			
		}
		
		/*double guess = 80000;

		for(int i=0;i<1000;++i)
		{
			guess = newton_raphson(guess);
		}


		if((int)(guess) <= 80000)
		{
			cout<<(int)(guess)<<"\n";
		}
		else
		{
			cout<<"80000\n";
		}*/
	}
} 


double newton_raphson(double guess)
{	
	double equation(double n);
	double derivative(double n);
	return guess - equation(guess)/derivative(guess);
}

double equation(double n)
{
	return -2*n*n*n + 3*n*n*(b-a) + 6*a*b*n + 100000000000000-x;
}

double derivative(double n)
{
	return -6*n*n + 6*n*(b-a) + 6*a*b;
}

long long srch(long long x,int left,int right)
{
	if(left == right)
	{
		return left;
	}
	int mid = (left+right)/2;

	if(equation(mid) >= 0)
	{
		return srch(x,left,mid);
	}
	else
	{
		return srch(x,mid+1,right);
	}
}