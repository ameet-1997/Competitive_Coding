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
	int n,k;
	cin>>n>>k;
	vi groups(k);

	rep(i,k)
	{
		cin>>groups[i];
	}

	int two = 2*n, four = n, one = 0;
	bool flag = true;

	rep(i,k)
	{
		if(four >= groups[i]/4)
		{
			four -= groups[i]/4;
			groups[i] %= 4;
		}
		else
		{	
			groups[i] -= 4*four;
			four = 0;
		}

		if(two >= groups[i]/2)
		{
			two -= groups[i]/2;
			groups[i] %= 2;
		}
		else
		{
			groups[i] -= 2*two;
			two = 0;
		}

		if(one >= groups[i])
		{
			one -= groups[i];
			groups[i] = 0;
		}
		else
		{
			groups[i] -= one;
			one = 0;
		}

		if(groups[i] == 1)
		{
			if(two > 0)
			{
				two--;
			}
			else if(four > 0)
			{
				four--;
				two++;
			}
			else if(one > 0)
			{
				one--;
			}
			else
			{
				flag = false;
				break;
			}
		}
		else if((groups[i] > 1)&&(groups[i] < 4))
		{	
			if(four)
			{
				four--;
				groups[i] = 0;
				if(groups[i] == 2)
				{
					one++;
				}
			}
			else
			{
				flag = false;
				break;				
			}
		}
		else if(groups[i] > 0)
		{
			flag = false;
			break;
		}

		// cout<<"The values are: "<<two<<" : "<<four<<endl;
	}

	if(flag)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
} 
