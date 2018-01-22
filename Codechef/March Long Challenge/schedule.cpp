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
 
string numbers;
 
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
 
		numbers.erase(numbers.begin(), numbers.end());
 
		cin>>numbers;

		if(k >= n)
		{
			cout<<"1\n";
		}
		else
		{
			int needed1 = 0,needed2 = 0;

			for(int i=0;i<n;++i)
			{
				if(i%2 == 0)
				{
					if(numbers[i] == '1')
					{
						needed1++;
					}
				}
				else
				{
					if(numbers[i] == '0')
					{
						needed1++;
					}
				}
			}

			for(int i=0;i<n;++i)
			{
				if(i%2 == 0)
				{
					if(numbers[i] == '0')
					{
						needed2++;
					}
				}
				else
				{
					if(numbers[i] == '1')
					{
						needed2++;
					}
				}
			}

			if(min(needed2,needed1) <= k)
			{
				cout<<"1\n";
			}
			else
			{	
				pqueue blocks;

				bool status = bool(int((numbers[0]-'0')));

				int count = 0;
				int current = 0;

				while(count < n)
				{
					if(status == bool(int((numbers[count]-'0'))))
					{
						current++;
						count++;
					}
					else
					{
						blocks.push(current);
						current = 0;
						status = bool(int((numbers[count]-'0')));
					}
				}

				blocks.push(current);

				while(k)
				{
					int temp = blocks.top();
					
					if(temp == 2)
					{
						break;
					}
					else
					{	
						blocks.pop();
						if(temp%2 == 0)
						{
							blocks.push(temp/2);
							blocks.push(temp/2-1);
							blocks.push(1);
						}
						else
						{
							blocks.push(temp/2);
							blocks.push(temp/2);
							blocks.push(1);							
						}
					}

					k--;
				}

				cout<<blocks.top()<<"\n";
			}			
		}
	}
}  
