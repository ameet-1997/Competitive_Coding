// Not tested yet

// Algorithm takes as input a graph and finds the shortest distance with respect to the source node to all other vertices
#include <bits/stdc++.h>

using namespace std;

#define VERTICES 100		// Change this to the number of vertices
#define INF 2147483647

vector< vector< pair<int,int> > > graph(VERTICES);		// Stores the graph as an adjacency list
vector<int> previous_node(VERTICES);								// Stores the vertex which is attached to the shortest path tree
vector<int> dist(VERTICES);							// Stores the distance of the vertex from the source vertex

// Source vertex assumed to be the one with index 0

void print_distance(int n)
{
			for(int i=0;i<n;++i)
		{
			cout<<dist[i]<<" ";
		}
		cout<<"\n";
}

int main()
{	
	void input_function(int m);		// Takes the input as a graph
	int BellmanFord(int n,int m);	// Calculates the shortest paths
	int n;							// Number of vertices
	int m;							// Number of edges

	cin>>n>>m;
	input_function(m);

	int flag = BellmanFord(n,m);

	if(flag == 0)		// Flag indicates the presence of a negative cycle
	{
		cout<<"Graph contains negative cycle\n";
	}
	else
	{
		cout<<"Distances to the vertices are as follows.\n";

		for(int i=0;i<n;++i)
		{
			cout<<dist[i]<<" ";
		}
		cout<<"\n";
	}
} 


void input_function(int m)
{
	for(int i=0;i<m;++i)
	{
		int vertex1, vertex2, weight;
		cin>>vertex1>>vertex2>>weight;

		graph[vertex1].push_back(make_pair(vertex2,weight));	// The entry contains the vertex number and the weight of the edge
	}	
}

int BellmanFord(int n,int m)
{
	// Source vertex can be changed here
	fill(dist.begin(),dist.begin()+n,INF);	// Initialising all distances to be infinity

	//cout<<dist[0]<<"\n";
	//print_distance(n);
	fill(previous_node.begin(),previous_node.begin()+n,-1);	// previous_node set to -1 for all vertices

	dist[0] = 0;	// Source node values changed
	previous_node[0] = 0;

	auto it = graph[0].begin();

	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n;++j)	// For all vertices in the graph
		{
			it = graph[j].begin();

			while(it != graph[j].end())
			{
				if((dist[j]!=INF) && (dist[j] + (*it).second < dist[(*it).first]))	// Check if including that egde reduces the distance to the other vertex
				{
					dist[(*it).first] = dist[j] + (*it).second;
					previous_node[(*it).first] = j;						// Change the previous_node array if the relaxation reduces the distance
				}
				it++;
			}
		}

		//print_distance(n);
	}


	for(int j=0;j<n;++j)	// For all vertices in the graph
	{
		it = graph[j].begin();

		while(it != graph[j].end())
		{
			if(dist[j] + (*it).second < dist[(*it).first])	// Check if including that egde reduces the distance to the other vertex
			{	
				return 0;	// Indicates the presence of negative cycle
			}
			it++;
		}
	}

	return 1;		// No negative cycle detected

}
