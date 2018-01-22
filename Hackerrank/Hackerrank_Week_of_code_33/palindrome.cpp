#include <bits/stdc++.h>

using namespace std;

vector<int> alphabets(1000000);
vector<int> numbers(10000);
vector< vector<int> > dp(1000);

int main()
{	
	int find_parent(int);
	void union_find(int,int);
	int find_palindrome(int);

	for(int i=0;i<1000;++i)
	{
		dp[i].resize(1000);
	}

	int n,k,m;
	cin>>n>>k>>m;

	fill(alphabets.begin(), alphabets.end(), -1);

	for(int i=0;i<k;++i)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		x = find_parent(x);
		y = find_parent(y);
		if(x != y)
		{
			union_find(x,y);
		}
	}

	for(int i=0;i<m;++i)
	{
		cin>>numbers[i];
		numbers[i]--;
		numbers[i] = find_parent(numbers[i]);
	}

	int answer = find_palindrome(m);
	
	cout<<answer<<"\n";
}

int find_parent(int x)
{
	if(alphabets[x] < 0)
	{
		return x;
	}
	else
	{
		alphabets[x] = find_parent(alphabets[x]);
		return alphabets[x];
	}
}

void union_find(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);

	if((-alphabets[x]) < (-alphabets[y]))
	{
		alphabets[x] = y;
	}
	else if((-alphabets[y]) < (-alphabets[x]))
	{
		alphabets[y] = x;
	}
	else
	{
		alphabets[x] = y;
		alphabets[y]--;
	}
}

int find_palindrome(int m)
{	
	for(int length=0;length<m;++length)
	{
		for(int i=0;i<=m-1-length;++i)
		{
			int j = length + i;
			dp[i][j] = 1;
			if(numbers[i] == numbers[j])
			{	
				if(length == 1)
				{
					dp[i][j] = 2;
				}
				else if(i+1 <= j-1)
				{
					dp[i][j] = 2 + dp[i+1][j-1];
				}	
			}

			if(length >= 1)
			{
				dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j-1]));
			}
		}
	}

	return dp[0][m-1];
}
