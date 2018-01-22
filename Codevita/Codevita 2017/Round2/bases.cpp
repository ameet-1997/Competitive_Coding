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
#define LIM 10000

//std::ios::sync_with_stdio(false); 
vi primes(LIM);

int main()
{	
	void sieve(int);
	sieve(LIM);
	int test;
	cin>>test;

	while(test--)
	{
		string s;
		cin>>s;

		int len = s.length();

		vi number;
		for(int i=0;i<len;++i)
		{
			if((s[i] >='0') && (s[i] <= '9'))
			{
				number.pb(s[i]-'0');
			}
			else
			{
				number.pb(s[i]-'A'+10);
			}
		}
		bool flag = false;

		int base = max(number[0], number[1])+1;
		f(i,base,37)
		{
			int final = number[0]*i+number[1];
			if(primes[final] == 0)
			{
				cout<<i<<" ";
				flag = true;
			}
		}

		if(flag)
		{	
			if(test)
			{
				cout<<endl;
			}
			
		}
		else
		{
			if(test)
			{
				cout<<"NONE\n";
			}
			else
			{
				cout<<"NONE";
			}
		}

	}
} 

void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(primes[i] == 0)
		{
			int current = 2*i;

			while(current <= n)
			{
				primes[current] = i;
				current += i;
			}
		}
	}
}
