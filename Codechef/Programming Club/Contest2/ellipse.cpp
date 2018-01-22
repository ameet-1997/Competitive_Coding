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
	int test;
	cin>>test;

	while(test--)
	{
		long double a,b,k;
		cin>>a>>b>>k;

		long double temp1,temp2;
		temp1 = min(a,b);
		temp2 = max(a,b);

		a = temp1;
		b = temp2;

		long double center = (a+b)/2;
		// cout<<center<<"\n";

		long double major = k/2;
		long double eccentricity = (b-a)/(2*major);

		if(eccentricity > 1)
		{
			cout<<"-1\n";
		}
		else
		{
			long double minor = major*major*(1- eccentricity*eccentricity);

			if(((center*center)/(major*major)) > 1)
			{
				cout<<"-1\n";
			}
			else if(abs(((center*center)/(major*major)) - 1) < (long double)(0.00001))
			{	
				cout<<1<<"\n";
				cout<<0<<" "<<0<<"\n";
			}
			else
			{	
				cout<<2<<"\n";
				long double answer = sqrt(minor*(1-((center*center)/(major*major))));
				cout<<0<<" ";
				cout << setprecision (10) << answer << endl;
				cout<<0<<" ";
				cout << setprecision (10) << -answer << endl;
			}
		}

	}
} 
