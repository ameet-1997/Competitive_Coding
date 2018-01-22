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

vector< vector<char> > tree(101);
vector< vector<int> > max_tree(101);
vector< vector<int> > dp(101);

int main()
{	
	int compute(int);
	int test;
	cin>>test;

	for(int i=0;i<101;++i)
	{
		tree[i].resize(101);
		dp[i].resize(101);
		max_tree[i].resize(101);
	}

	for(int zz=1;zz<=test;++zz)
	{
		int n,m,k;
		cin>>n>>m>>k;

		for(int i=0;i<n;++i)
		{
			fill(dp[i].begin(),dp[i].end(),0);
			fill(max_tree[i].begin(), max_tree[i].end(), 0);
		}

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>tree[i][j];
			}
		}

		
		/*for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cout<<tree[i][j];
			}
			cout<<"\n";
		}*/

		for(int i=0;i<n;++i)
		{
			int j=0;
			int left,right;
			while(j < m)
			{	
				if(tree[i][j] == '#')
				{	
					left = j;
					while((tree[i][j] == '#')&&(j<m))
					{
						j++;
					}
					j--;
					right = j;

					//cout<<"Row number : "<<i<<" :: "<<left<<" ,"<<right<<"\n";

					for(int k = left;k<=right;++k)
					{
						max_tree[i][k] = min(k-left,right-k)+1;
					}
				}
				j++;
			}
		}

		/*cout<<"Max_Tree\n";

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cout<<max_tree[i][j]<<" ";
			}
			cout<<"\n";
		}*/

		for(int j=0;j<m;++j)
		{
			for(int i=0;i<n;++i)
			{
				int k=i;
				while((max_tree[k][j] >= (k-i+1))&&(k<n))
				{
					k++;
				}
				k--;

				dp[i][j] = k-i+1;
			}
		}

		long long final_answer = INT_MIN;

		/*int final_answer = INT_MIN;

		for(int i=0;i<n;++i)
		{
			final_answer = max(final_answer, *(max_element(dp[i].begin(), dp[i].begin()+m)));
		}

		cout<<"Case #"<<zz<<": "<<final_answer*((long long)(final_answer))<<"\n";
		*/
	}
}  
