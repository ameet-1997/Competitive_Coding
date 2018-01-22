#include <iostream>

using namespace std;

int a[100010];
long long b[100010];

int main()
{	
	int find_parent(int);
	void do_union(int,int);
	int test;
	cin>>test;



	for(int zz=0;zz<test;++zz)
	{	
		long long sum = 0;
		int n,m;
		cin>>n>>m;

		for(int i=0;i<n;++i)
		{
			a[i] = -1;
			b[i] = 0;
		}

		int x,y;

		for(int i=0;i<m;++i)
		{
			cin>>x>>y;
			do_union(x-1,y-1);
		}

		long long temp;
		int parent;

		for(int i=0;i<n;++i)
		{
			parent = find_parent(i);
			cin>>temp;
			b[parent] = b[parent] + temp;
		}

		for(int i=0;i<n;++i)
		{
			if(b[i] > sum)
			{
				sum = b[i];
			}
		}


		cout<<sum<<"\n";




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