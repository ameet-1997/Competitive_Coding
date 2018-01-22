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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
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


map<string,int> words;

vi relations(100000);

vector< set<int> > antonyms(100000);

int main()
{	
	int find_parent(int n);
	void congregate(int,int);

	int n,m,q;

	cin>>n>>m>>q;


	fill(relations.begin(),relations.begin()+n,-1);

	string temp;

	for(int i=0;i<n;++i)
	{
		cin>>temp;
		words[temp] = i;
	}

	string temp2;

	for(int i=0;i<m;++i)
	{
		int choice;
		cin>>choice;
		cin>>temp;
		cin>>temp2;

		if(choice == 1)
		{
			int num1,num2;

			num1 = find_parent(words[temp]);	// Find parents of respective words
			num2 = find_parent(words[temp2]);

			if(num1 != num2)
			{
				// Check if they are antonyms
				if(antonyms[num1].find(num2) != antonyms[num1].end())
				{
					cout<<"NO\n";
				}
				else
				{
					if((-relations[num1]) > (-relations[num2]))
					{
						relations[num2] = num1;
						antonyms[num1].insert(antonyms[num2].begin(),antonyms[num2].end());
						//antonyms[num2].erase(antonyms[num2].begin(),antonyms[num2].end());
					}
					else if((-relations[num2]) > (-relations[num1]))
					{
						relations[num1] = num2;
						antonyms[num2].insert(antonyms[num1].begin(),antonyms[num1].end());
						//antonyms[num1].erase(antonyms[num1].begin(),antonyms[num1].end());
					}
					else
					{
						relations[num1] = num2;
						antonyms[num2].insert(antonyms[num1].begin(),antonyms[num1].end());
						relations[num2]--;
					}

					cout<<"YES\n";					
				}
			}
			else
			{
				cout<<"YES\n";
			}

		}
		else
		{
			int num1,num2;

			num1 = find_parent(words[temp]);
			num2 = find_parent(words[temp2]);

			if(num1 == num2)
			{
				cout<<"NO\n";
			}
			else
			{	
				int flag = 1;
				auto it = antonyms[num2].begin();
				while(it != antonyms[num2].end())
				{
					if(antonyms[num1].find(*it) != antonyms[num1].end())
					{
						flag = 0;
						break;
					}
					it++;
				}

				if(flag)
				{	
					it = antonyms[num1].begin();
					while(it != antonyms[num1].end())
					{
						if(antonyms[num2].find(*it) != antonyms[num2].end())
						{
							flag = 0;
							break;
						}
						it++;
					}					
				}

				if(flag == 0)
				{
					cout<<"NO\n";
				}
				else
				{	
					congregate(num1,num2);	//Makes the antonyms of antonyms as synonyms

					//antonyms[num1].insert(num2);
					//antonyms[num2].insert(num1);
					cout<<"YES\n";					
				}

			}			
		}
	}

	string check1,check2;

	for(int i=0;i<q;++i)
	{
		cin>>check1>>check2;

		int n1,n2;
		n1 = words[check1];
		n2 = words[check2];

		n1 = find_parent(n1);
		n2 = find_parent(n2);

		if(n1 == n2)
		{
			cout<<"1\n";
		}
		else
		{
			if(antonyms[n1].find(n2) != antonyms[n1].end())
			{
				cout<<"2\n";
			}
			else
			{
				cout<<"3\n";
			}
		}
	}


} 

int find_parent(int n)
{
	if(relations[n] >= 0)
	{
		relations[n] = find_parent(relations[n]);
		return relations[n];
	}
	else
	{
		return n;
	}
}


void congregate(int n1, int n2)
{
	int union_operation(int,int);

	auto it = antonyms[n2].begin();

	int final1 = -1000000,final2 = -1000000;

	while(it != antonyms[n1].end())
	{	
		if(final1 == -1000000)
		{
			final1 = union_operation(n1,*it);	
		}
		else
		{
			final1 = union_operation(final1,*it);
		}
		it++;
	}
}


int union_operation(int n1,int n2)
{
	int num1 = find_parent(n1);
	int num2 = find_parent(n2);

	if(num2 == num1)
	{
		return num1;
	}

	if((-relations[num1]) > (-relations[num2]))
	{
		relations[num2] = num1;
		antonyms[num1].insert(antonyms[num2].begin(),antonyms[num2].end());
		return num1;
		//antonyms[num2].erase(antonyms[num2].begin(),antonyms[num2].end());
	}
	else if((-relations[num2]) > (-relations[num1]))
	{
		relations[num1] = num2;
		antonyms[num2].insert(antonyms[num1].begin(),antonyms[num1].end());
		return num2;
		//antonyms[num1].erase(antonyms[num1].begin(),antonyms[num1].end());
	}
	else
	{
		relations[num1] = num2;
		antonyms[num2].insert(antonyms[num1].begin(),antonyms[num1].end());
		relations[num2]--;
		return num2;
	}
}
