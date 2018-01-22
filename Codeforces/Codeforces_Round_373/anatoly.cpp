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
	int n;
	cin>>n;

	int min_answer = INT_MAX;

	string cockroach;
	cin>>cockroach;

	int reds_out_of_place = 0, blacks_out_of_place = 0;

	int len = cockroach.length();

	for(int i=0;i<len;++i)
	{
		if(i%2 == 0)
		{
			if(cockroach[i] == 'b')
			{
				blacks_out_of_place++;
			}
		}
		else
		{
			if(cockroach[i] == 'r')
			{
				reds_out_of_place++;
			}			
		}
	}

	min_answer = abs(blacks_out_of_place- reds_out_of_place) + min(blacks_out_of_place,reds_out_of_place);

	blacks_out_of_place = 0;
	reds_out_of_place = 0;

	for(int i=0;i<len;++i)
	{
		if(i%2 == 0)
		{
			if(cockroach[i] == 'r')
			{
				reds_out_of_place++;
			}
		}
		else
		{
			if(cockroach[i] == 'b')
			{
				blacks_out_of_place++;
			}			
		}
	}

	int min2 = abs(blacks_out_of_place- reds_out_of_place) + min(blacks_out_of_place,reds_out_of_place);
	min_answer = min(min_answer, min2);

	cout<<min_answer<<"\n";
}