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
		int n;
		cin>>n;

		vi numbers(n);
		rep(i,n)
		{
			cin>>numbers[i];
		}

		int current_state = 1;
		// vi flags(7);
		// fill(flags.begin(), flags.end(), 0);
		bool flag = true;
		bool one = false;

		for(int i=0;i<=(n-1)/2;++i)
		{
			if(numbers[i] == numbers[n-i-1])
			{	
				if(numbers[i] != current_state)
				{
					if((numbers[i] == current_state+1)&&(current_state+1 <= 7))
					{
						current_state += 1;
						// flags[current_state-1] = 1;
					}
					else
					{
						flag = false;
						break;
					}
				}
				else
				{
					if(current_state == 1)
					{
						one = true;
					}
				}
			}
			else
			{	
				flag = false;
				break;
			}
		}

		if((flag)&&(current_state >= 7))
		// if(flag)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}

	}
} 
