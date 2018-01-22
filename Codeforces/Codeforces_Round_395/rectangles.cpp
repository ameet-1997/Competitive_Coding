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
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
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

class rectangle{
	public:
	int rectangle_number;
	int x1;
	int y1;
	int x2;
	int y2;

	bool operator <(rectangle &r)
	{
		if(x1 <= r.x1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool fory(rectangle r1,rectangle r2)
{
	if(r1.y1 < r2.y1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool for_binary_search_1(rectangle r1,rectangle r2)
{
	if(r1.x1 < r2.x1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool for_binary_search_2(rectangle r1,rectangle r2)
{
	if(r1.y1 < r2.y1)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

vector<rectangle> figures(1000000);
vector< vector<int> > graph(1000000);
vi colours(1000000);

int main()
{
	int n;
	cin>>n;

	int x1,y1,x2,y2;

	for(int i=0;i<n;++i)
	{
		cin>>x1>>y1>>x2>>y2;
		figures[i].rectangle_number = i;
		figures[i].x1 = min(x1,x2);
		figures[i].y1 = min(y1,y2);
		figures[i].x2 = max(x1,x2);
		figures[i].y2 = max(y1,y2);
	}

	sort(figures.begin(),figures.begin()+n);

	/*for(int i=0;i<n;++i)
	{
		cout<<figures[i].x1<<" ";
	}
	cout<<"\n";*/

	rectangle temp;

	for(int i=0;i<n;++i)
	{
		pair< vector<rectangle>::iterator, vector<rectangle>::iterator > ranges ;
		temp.x1 = figures[i].x2;
		ranges = equal_range(figures.begin(), figures.begin()+n, temp, for_binary_search_1);


		auto it = ranges.first;

		while(it != ranges.second)
		{	

			if((it->y1 < figures[i].y2)||(it->y2 > figures[i].y1))
			{
				graph[figures[i].rectangle_number].pb(it->rectangle_number);
				graph[it->rectangle_number].pb(figures[i].rectangle_number);
				it++;				
			}

		}
	}

	sort(figures.begin(),figures.begin()+n,fory);

	/*for(int i=0;i<n;++i)
	{
		cout<<figures[i].y1<<" ";
	}
	cout<<"\n";*/

	for(int i=0;i<n;++i)
	{
		pair< vector<rectangle>::iterator, vector<rectangle>::iterator > ranges ;
		temp.y1 = figures[i].y2;
		ranges = equal_range(figures.begin(), figures.begin()+n, temp, for_binary_search_2);


		auto it = ranges.first;

		while(it != ranges.second)
		{
			if((it->y1 < figures[i].y2)||(it->y2 > figures[i].y1))
			{
				graph[figures[i].rectangle_number].pb(it->rectangle_number);
				graph[it->rectangle_number].pb(figures[i].rectangle_number);
				it++;				
			}
		}
	}


	int c = 0;

	for(int i=0;i<n;++i)
	{
		c+=graph[i].size();
	}

	cout<<c<<"\n";

	fill(colours.begin(),colours.begin()+n,-1);

	vi check(4);
	for(int i=0;i<n;++i)
	{
		fill(check.begin(),check.begin()+4,0);

		auto it = graph[i].begin();

		while(it!=graph[i].end())
		{
			if(colours[*it] != -1)
			{
				check[colours[*it] - 1] = 1;
			}
			it++;
		}

		if(check[0] == 0)
		{
			colours[i] = 1;
		}
		else if(check[1] == 0)
		{
			colours[i] = 2;
		}
		else if(check[2] == 0)
		{
			colours[i] = 3;
		}
		else if(check[3] == 0)
		{
			colours[i] = 4;
		}
		else
		{
			cout<<"NO\n";
			exit(0);
		}
	}


	cout<<"YES\n";
	for(int i=0;i<n;++i)
	{
		cout<<colours[i]<<"\n";
	}


} 
