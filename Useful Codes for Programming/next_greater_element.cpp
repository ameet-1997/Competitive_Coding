// Find the next greatest element in the array using stacks
// Find the nearest element to the right of each element, which is greater than the current element
// Time Complexity - O(n)
// Space Complexity - O(n)
// Tested to the best of my knowledge

//Author: Ameet Deshpande


#include <bits/stdc++.h>

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
#define ll logreater_stack logreater_stack
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

int main()
{
	int n;
	cin>>n;

	vi numbers(n);
	vi next_greater(n);

	rep(i,n)
	{
		cin>>numbers[i];
	}

	// Copy Code from here

	fill(next_greater.begin(), next_greater.end(), -1);
	stack<pii> greater_stack;

	for(int i=0;i<n;++i)
	{
		while((!greater_stack.empty())&&(greater_stack.top().first <= numbers[i]))
		{
			next_greater[greater_stack.top().second] = i;
			greater_stack.pop();
		}
		greater_stack.push(mp(numbers[i],i));
	}

	// Code is till here

	cout<<"The numbers are : "<<endl;
	rep(i,n)
	{
		cout<<next_greater[i]<<" ";
	}
	cout<<endl;
} 
