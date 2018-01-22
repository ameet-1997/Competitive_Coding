#include <bits/stdc++.h>
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
	int n,m,i,j,a,b;
	cin>>n>>m>>j>>i>>a>>b;

	// int rt, lt, rb, lb;
	int answer = INT_MAX;
	bool flag = false;

	if(((m-i)%a == 0)&&((n-j)%b == 0))
	{
		if((((m-i)/a)%2) == (((n-j)/b)%2))
		{
			answer = min(answer, max(((m-i)/a), ((n-j)/b)));
			flag = true;
		}
	}

	// cout<<"Answer is : "<<answer<<endl;

	if(((i-1)%a == 0)&&((n-j)%b == 0))
	{
		if((((i-1)/a)%2) == (((n-j)/b)%2))
		{
			answer = min(answer, max(((i-1)/a), ((n-j)/b)));
			flag = true;
		}
	}

	// cout<<"Answer is : "<<answer<<endl;

	if(((i-1)%a == 0)&&((j-1)%b == 0))
	{
		if((((i-1)/a)%2) == (((j-1)/b)%2))
		{
			answer = min(answer, max(((i-1)/a), ((j-1)/b)));
			flag = true;
		}
	}

	// cout<<"Answer is : "<<answer<<endl;	

	if(((m-i)%a == 0)&&((j-1)%b == 0))
	{
		if((((m-i)/a)%2) == (((j-1)/b)%2))
		{
			answer = min(answer, max(((m-i)/a), ((j-1)/b)));
			flag = true;
		}
	}

	// cout<<"Answer is : "<<answer<<endl;		

	if(flag)
	{
		cout<<answer<<endl;
	}
	else
	{
		cout<<"Poor Inna and pony!"<<endl;
	}
}