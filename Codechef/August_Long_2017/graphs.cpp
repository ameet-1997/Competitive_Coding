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

vector< vi > graph(100001);

int main()
{	
	pair<bool,int> different_element(vi&, vi&, int);
	void fill_initial_values(int, vi&);
	int test;
	cin>>test;

	while(test--)
	{
		int n,m;
		cin>>n>>m;
		rep(i,n)
		{
			graph[i].erase(graph[i].begin(), graph[i].end());
		}

		bool flag = true;
		vi answer(n+1);

		rep(i,m)
		{
			int x,y;
			cin>>x>>y;

			if(x >= y)		// Backward directed edge
			{
				flag = false;
			}
			graph[x].pb(y);
		}

		rep(i,n+1)
		{
			sort(graph[i].begin(), graph[i].end());
		}

		fill_initial_values(n, answer);

		rep(i,n)	// Last but one vertice
		{
			pair<bool,int> temp = different_element(graph[i], graph[i+1], i+1);
			if(temp.first)
			{
				if(temp.second != -1)
				{	
					answer[temp.second] = answer[i+1];
				}
			}
			else
			{	
				flag = false;
				break;
			}
		}

		if(flag)
		{
			rep(i,n)
			{	
				if(answer[i+1] > 0)
				{
					cout<<answer[i+1]<<" ";	
				}
				else
				{
					cout<<"1 ";
				}
				
			}
			cout<<"\n";
		}	
		else
		{	
			cout<<"-1\n";
		}
	}
}

pair<bool, int> different_element(vi& a, vi& b,int check)
{	
	int sz1 = a.size();
	int sz2 = b.size();

	if(sz1 == sz2+1)
	{
		if(a[0] != check)
		{
			return mp(false, -1);
		}
		for(int i=0;i<sz2;++i)
		{
			if(a[i+1] != b[i])
			{
				return mp(false, -1);
			}
		}

		return mp(true,-1);
	}
	else if(sz1 == sz2)
	{	
		if(a[0] != check)
		{
			return mp(false, -1);
		}
		int p = 1, q = 0;
		int different;
		int cal = 0;
		while((p < sz1)&&(q < sz2))
		{	
			if(a[p] > b[q])
			{	
				different = q;
				q++;
				cal++;
			}
			else if(a[p] < b[q])
			{
				different = q;
				p++;
				cal++;
			}
			else
			{
				p++;
				q++;
			}

			if(cal > 1)
			{
				return mp(false,-1);
			}
		}

		if(cal == 0)
		{
			return mp(true, b[sz2-1]);
		}
		else if(cal > 1)
		{
			return mp(false, -1);
		}
		else
		{
			return mp(true, b[different]);
		}
	}
	else
	{
		return mp(false,-1);
	}
}

void fill_initial_values(int n, vi& answer)
{	
	int counter = 1;
	auto it = graph[0].begin();
	int prev_index = -1;
	while(it != graph[0].end())
	{
		prev_index = *it;
		answer[*it] = counter;
		counter++;
		it++;
	}
}