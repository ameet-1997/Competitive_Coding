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

using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< ll >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< ll,ll >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<ll,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< ll,vi ,greater< ll > >
# define INF (100000000000000000)

//std::ios::sync_with_stdio(false); 

ll number_of_cities,x;
ll old_cities, m, s;

class Graph
{
public:
    ll V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex 
    // and weight pair for every edge
    list< pair<ll, ll> > *adj;
 

    Graph(ll V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(ll u, ll v, ll w);
 
    // prints shortest path from s
    vector<ll> shortestPath(ll s);
};
 
// Allocates memory for adjacency list
Graph::Graph(ll V)
{
    this->V = V;
    adj = new list< pair<ll, ll> >[V];
}
 
void Graph::addEdge(ll u, ll v, ll w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
// Prints shortest paths from src to all other vertices
vector<ll> Graph::shortestPath(ll src)
{
    set< pair<ll, ll> > setds;
 
    vector<ll> dist(V, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    while (!setds.empty())
    {
        pair<ll, ll> tmp = *(setds.begin());
        setds.erase(setds.begin());

        ll u = tmp.second;
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<ll, ll> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            ll v = (*i).first;
            ll weight = (*i).second;
 
            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
 
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}
 
int main()
{		
	ll test;
	cin>>test;

	while(test--)
	{
		
		cin>>number_of_cities>>old_cities>>x>>m>>s;
		Graph g(number_of_cities);

		

		for(ll i=0;i<m;++i)
		{	
			ll x1,y,weight;
			cin>>x1>>y>>weight;
			g.addEdge(x1-1,y-1,weight);
		}

        if(s <= old_cities)
        {
            for(ll i = 0;i<old_cities;++i)
            {
                if(i != (s-1))
                {
                    g.addEdge(s-1,i,x);    
                }
            }
        }
        else
        {   
            if(old_cities <= 500)
            {
                for(ll i=0;i<old_cities;++i)
                {
                    for(ll j=i+1;j<old_cities;++j)
                    {
                        g.addEdge(i,j,x);
                    }
                }
            }
            else
            {
                vector<ll> temp_distance = g.shortestPath(s-1);

                int temp_min = *(min_element(temp_distance.begin(), temp_distance.begin()+old_cities));

                for(int i=0;i<old_cities;++i)
                {
                    if(temp_distance[i] > temp_min + x)
                    {
                        temp_distance[i] = temp_min + x;
                    }
                }

                for(int i=0;i<old_cities;++i)
                {
                    g.addEdge(s-1,i,temp_distance[i]);
                }
            }

        }

		vector<ll> vr = g.shortestPath(s-1);

        for(int i=0;i<g.V;++i)
        {
            cout<<vr[i]<<" ";
        }
        cout<<"\n";
	}
}