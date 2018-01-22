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
		string temp;
		cin>>temp;

		vi possible(10);

		auto it = temp.begin();

		while(it != temp.end())
		{
			possible[(*it)-'0']++;
			it++;
		}

		for(int i='A';i<='Z';++i)
		{
			int index1, index2;
			index1 = i/10;
			index2 = i%10;

			bool flag = false;

			if((index2!=index1)&&(possible[index1])&&(possible[index2]))
			{
				flag = true;
			}
			else if((index1 == index2)&&(possible[index2] > 1))
			{
				flag = true;
			}

			if(flag)
			{
				cout<<(char)i;
			}
		}

		cout<<endl;
	}
} 
