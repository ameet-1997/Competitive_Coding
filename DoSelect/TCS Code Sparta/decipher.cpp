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


long long pow_func(int a,int b)
{
	ll answer = 1;

	for(int i = 0;i<b;++i)
	{
		answer*=a;
	}
	return answer;
}

map<char,int> alphabet;
int main()
{
	int test;
	cin>>test;

	for(char i = 'a';i<='z';++i)
	{
		alphabet[i] = i-'a'+1;
	}


	while(test--)
	{
		int k,b;
		cin>>k>>b;

		vector<int> magic_numbers(10000);

		for(int i=0;i<k;++i)
		{
			cin>>magic_numbers[i];
		}

		vector<ll> final;

		int words = 0;

		char temp;
		cin>>temp;
		string sentence;
		getline(cin,sentence,'\n');

		sentence.insert(sentence.begin(),temp);
		sentence.push_back(' ');

		int till = sentence.length();

		string s;

		for(int i=0;i<till;++i)
		{	
			if(sentence[i] == ' ')
			{	
				ll answer = 0;
				auto it = s.begin();

				while(it != s.end())
				{
					answer += (alphabet[*it])* (pow_func(b,magic_numbers[it-s.begin()]));
					it++;
				}

				if(answer)
				{
					final.push_back(answer);	
				}

				s.erase(s.begin(),s.end());				
			}
			else
			{
				s.push_back(sentence[i]);	
			}
			
		}

		auto it = final.begin();

		while(it != (final.end()-1))
		{	
			cout<<*it<<"+";	
			it++;
		}

		cout<<*it<<"\n";
	}
} 
