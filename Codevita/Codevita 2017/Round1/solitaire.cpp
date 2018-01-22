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
	char c;
	c = getchar();

	while(n--)
	{	
		string temp1;
		getline(cin, temp1);

		string temp;

		int len = temp1.length();

		rep(i,len)
		{
			if(i%2 == 0)
			{
				temp.pb(temp1[i]);
			}
		}

		int number_of_stack = 0;

		int index = 0;

		len = temp.length();

		rep(i,len)
		{
			if(temp[i] != '0')
			{
				number_of_stack++;
			}

			char current = temp[i];
			temp[i] = '0';
			int j=i+1;
			while(j<len)
			{
				if((temp[j] != '0')&&(temp[j] <= current))
				{
					current = temp[j];
					temp[j] = '0';
				}
				j++;
			}

			//cout<<"The string is : "<<temp<<"\n";
		}

		if(n)
		{
			cout<<number_of_stack<<"\n";
		}
		else
		{
			cout<<number_of_stack;
		}
		

		//cout<<temp<<"\n";
	}
	return 0;
} 
