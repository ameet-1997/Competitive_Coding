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
	int number_of_days(int);
	int m,d;
	cin>>m>>d;

	int number = number_of_days(m);

	int answer = 1;
	number = number - (7 - d + 1);

	if(number%7 == 0)
	{
		answer = answer + number/7;
	}
	else
	{
		answer = answer + number/7 + 1;
	}

	cout<<answer<<"\n";

}

int number_of_days(int n)
{
	switch(n)
	{
		case 1: return 31;break;
		case 2: return 28;break;
		case 3: return 31;break;
		case 4: return 30;break;
		case 5: return 31;break;
		case 6: return 30;break;
		case 7: return 31;break;
		case 8: return 31;break;
		case 9: return 30;break;
		case 10: return 31;break;
		case 11: return 30;break;
		case 12: return 31;break;
	}
}