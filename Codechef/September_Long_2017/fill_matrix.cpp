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

vector< vi > graph(100000);
vi numbers(100000);
vi colorArr(100000);
vii queries(1000000);

int main()
{	
	void do_union(int,int);
	int find_parent(int);
	bool run_check(int,int);
	int test;
	cin>>test;

	while(test--)
	{	
		int n,q;
		cin>>n>>q;

		rep(i,n)
		{
			graph[i].erase(graph[i].begin(), graph[i].end());
		}
		fill(numbers.begin(), numbers.begin()+n, -1);

		// int source = -1;

		int count_queries = 0;
		rep(i,q)
		{
			int x,y,val;
			cin>>x>>y>>val;
			x--;y--;
			if(val == 0)
			{
				do_union(x, y);
			}
			else
			{	
				queries[count_queries].first = x;
				queries[count_queries].second = y;
				count_queries++;
			}
		}

		// Process other types of queries

		rep(i, count_queries)
		{
			int par1 = find_parent(queries[i].first);
			int par2 = find_parent(queries[i].second);
			// source = par1;
			graph[par1].pb(par2);
			graph[par2].pb(par1);
		}

		/*******
		Display the graph
		*******/

		// for(int i=0;i<n;++i)
		// {
		// 	cout<<"Row number "<<i+1<<" : ";
		// 	auto it = graph[i].begin();
		// 	while(it != graph[i].end())
		// 	{
		// 		cout<<*it<<" ";
		// 		it++;
		// 	}
		// 	cout<<endl;
		// }

		fill(colorArr.begin(), colorArr.begin()+n, -1);
		bool flag = true;

		for(int i=0;i<n;++i)
		{
			if(colorArr[i] < 0)
			{
				flag = flag && run_check(n,i);
			}
			if(!flag)
			{
				break;
			}
		}

		if(flag)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
}



void do_union(int x,int y)
{
	int find_parent(int);

	int x_p,y_p;

	x_p = find_parent(x);
	y_p = find_parent(y);

	if(x_p == y_p)
	{
		return;
	}

	if(-numbers[x_p] > -numbers[y_p])
	{
		numbers[y_p] = x_p;
	}
	else if(-numbers[x_p] < -numbers[y_p])
	{
		numbers[x_p] = y_p;
	}
	else
	{
		numbers[y_p] = x_p;
		numbers[x_p]--;
	}
}


int find_parent(int x)
{
	if(numbers[x] < 0)
	{
		return x;
	}
	else
	{
		numbers[x] = find_parent(numbers[x]);	//Doing path compression
		return numbers[x];
	}
} 


bool run_check(int n, int source)
{
 
    // Assign first color to source
    colorArr[source] = 1;
 
    queue <int> q;
    q.push(source);
 
    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
 
         
 
        // Find all non-colored adjacent vertices
       auto it = graph[u].begin();
        while(it != graph[u].end())
        {
            // An edge from u to v exists and destination v is not colored
            if (colorArr[*it] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[*it] = 1 - colorArr[u];
                q.push(*it);
            }
 
            else if (colorArr[*it] == colorArr[u])
                return false;

            it++;
        }
    }

    return true;	
}