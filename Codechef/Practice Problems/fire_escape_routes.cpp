#include <iostream>
#include <algorithm>
#include <vector>

#define mod 1000000007


using namespace std;


vector<int> a(100000);
vector<int> number(100000);


int main()
{	
	void do_union(int,int);
	int test;
	int m,n;

	cin>>test;
	for(int zz=0;zz<test;++zz)
	{
		cin>>n;
		cin>>m;
		fill(a.begin(),a.begin()+n,-1);
		fill(number.begin(),number.begin()+n,1);

		int x1,y1;

		for(int i=0;i<m;++i)
		{
			cin>>x1>>y1;
			do_union(x1-1,y1-1);
		}

		long long answer = 1;
		int count = 0;

		for(int i=0;i<n;++i)
		{
			if(a[i] < 0)
			{
				answer = answer*number[i];
				answer = answer % mod;
				count++;
			}
		}

		cout<<count<<" "<<answer<<"\n";
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
		number[x_p] = number[y_p] + number[x_p];
	}
	else if(-a[x_p] < -a[y_p])
	{
		a[x_p] = y_p;
		number[y_p] = number[y_p] + number[x_p];
	}
	else
	{
		a[y_p] = x_p;
		a[x_p]--;
		number[x_p] = number[y_p] + number[x_p];
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