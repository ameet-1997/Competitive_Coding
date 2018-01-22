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

vector<int> encryption(127);
string s;
vector<int> answer;
vector<int> till_decimal;
vector<int> after_decimal;

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int rules;
		cin>>rules;

		answer.erase(answer.begin(),answer.end());
		till_decimal.erase(answer.begin(),answer.end());
		after_decimal.erase(answer.begin(),answer.end());

		fill(encryption.begin(),encryption.end(),0);

		f(i,0,rules)
		{
			char c;
			int p;
			cin>>c>>p;
			encryption[c] = p;
		}

		cin>>s;
		string::iterator it = s.begin();

		if(rules)
		{
			while(it != s.end())
			{
				answer.push_back(encryption[*it]);
				it++;
			}			
		}
		else
		{
			while(it != s.end())
			{
				answer.push_back(*it-'0');
				it++;
			}			
		}


		vector<int>::iterator it1 = answer.begin();
		bool flag = true;

		while(it1 != answer.end())
		{	
			if(*it1 == '.')
			{
				flag = false;
				it++;
				continue;
			}

			if(flag)
			{
				till_decimal.push_back(*it1);
			}
			else
			{
				after_decimal.push_back(*it1);
			}
			it1++;
		}

		flag = false;

		it1 = till_decimal.begin();

		while(it1 != till_decimal.end())
		{	
			if(*it1 != 0)
			{
				flag = true;
			}

			if(flag)
			{
				cout<<*it1;
			}

			it1++;

		}

		till_decimal.erase(till_decimal.begin(),till_decimal.end());

		auto it2 = after_decimal.rbegin();

		flag = false;

		while(it2 != after_decimal.rend())
		{	
			if(*it2 != 0)
			{
				flag = true;
			}

			if(flag)
			{
				till_decimal.push_back(*it2);
			}

			it2++;

		}

		if(!till_decimal.empty())
		{
			cout<<".";

			auto it = till_decimal.rbegin();

			while(it != till_decimal.rend())
			{
				cout<<*it;
			}
		}
		cout<<"\n";

	}
} 
