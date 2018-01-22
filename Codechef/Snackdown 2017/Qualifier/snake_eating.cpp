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

vi snakes(1000000);
vi segment_tree(3000000);

int main()
{	
	std::ios::sync_with_stdio(false);

	void build_segment_tree(int,int,int);
	void query_segment_tree(int,int,int,int,int);
	void comparing_function(int,int);

	int test;
	cin>>test;

	while(test--)
	{
		int number_of_snakes, queries;
		cin>>number_of_snakes>>queries;

		rep(i,number_of_snakes)
		{
			cin>>snakes[i];
		}

		sort(snakes.begin(), snakes.begin()+number_of_snakes);

		build_segment_tree(0,number_of_snakes,0);


		rep(i, queries)
		{
			int k;
			cin>>k;

			int index = lower_bound(snakes.begin(), snakes.begin()+number_of_snakes, k) - snakes.begin();
			int remaining = index-1;

			int total_snakes = number_of_snakes - index;

			int from  = index-1;
			


			cout<<total_snakes<<"\n";
		}
	}
} 

/*
while((remaining > 0)&&(from > 0))
{
	if(remaining >= k - snakes[from])
	{
		remaining -= k - snakes[from];
		remaining--;
		total_snakes++;
		from--;
	}
	else
	{
		break;
	}
}
*/

void comparing_function(int a,int b)
{

}

int bn_search(int i, int j, int value)
{
	
}


void build_segment_tree(int i, int j, int node)
{
	if(i == j)
	{
		segment_tree[node] = snakes[i];
		return segment_tree[node];
	}
	else
	{
		segment_tree[node] = build_segment_tree(i,(i+j)/2, 2*node+1) + build_segment_tree((i+j)/2, j, 2*node+2);
		return segment_tree[node];
	}
}


int query_segment_tree(int i, int j, int left, int right, int node)
{
	if((right < i)||(j<left))
	{
		return 0;
	}

	if((left >= i)&&(right <= j))
	{
		return segment_tree[node];
	}
	else
	{
		return query_segment_tree(i, j, left, (left+right)/2, 2*node+1) + query_segment_tree(i, j, (left+right)/2+1, right, 2*node+2);
	}
}