#include <iostream>

using namespace std;

int weight[100000];
int beauties[100000];
int a[100010];
int K[1010][1010];

int parent_beauty[100000];
int parent_weight[100000];

int main()
{
	int find_parent(int);
	void do_union(int,int);
	int knapSack(int W, int wt[], int val[], int n);

	int n,pairs,max_weight;

	cin>>n>>pairs>>max_weight;

	for(int i=0;i<n;++i)
	{
		cin>>weight[i];
		a[i] = -1;
	}

	for(int i=0;i<n;++i)
	{
		cin>>beauties[i];
	}

	for(int i=0;i<pairs;++i)
	{
		int x,y;
		cin>>x>>y;
		do_union(x-1,y-1);
	}

	for(int i=0;i<n;++i)
	{
		int p = find_parent(i);
		parent_weight[p] += weight[i];
		parent_beauty[p] += beauties[i];
	}

	int check = 0;
	for(int i=0;i<n;++i)
	{
		if(parent_beauty[i] > 0)
		{
			parent_beauty[check] = parent_beauty[i];
			parent_weight[check] = parent_weight[i];
			check++;
		}
	}



long long answer = knapSack(max_weight+1,parent_weight,parent_beauty,check);
cout<<answer<<"\n";



} 


 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{	
	int max(int,int);
   int i, w;
   //int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
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

	if(-a[x_p] > -a[y_p])
	{
		a[y_p] = x_p;
	}
	else if(-a[x_p] < -a[y_p])
	{
		a[x_p] = y_p;
	}
	else
	{
		a[y_p] = x_p;
		a[x_p]--;
	}
}


int find_parent(int x)
{
	if(a[x] < 0)
	{
		return x;
	}
	else
	{
		a[x] = find_parent(a[x]);	//Doing path compression
		return a[x];
	}
}