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

string name1,name2;

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		cin>>name1>>name2;

		vi characters1(26,0);
		vi characters2(26,0);

		string::iterator it = name1.begin();

		while(it != name1.end())
		{
			characters1[*it-'a']++;
			it++;
		}

		it = name2.begin();
		while(it != name2.end())
		{
			characters2[*it-'a']++;
			it++;
		}


		int answer = 0;

		for(int i=0;i<26;++i)
		{
			if((characters1[i] == 0)||(characters2[i] == 0))
			{
				answer = answer + characters2[i] + characters1[i];
			}
		}
		
		switch(answer%5)
		{
			case 0:cout<<"FEAML\n";break;
			case 1:cout<<"LFAME\n";break;
			case 2:cout<<"FLAME\n";break;
			case 3:cout<<"FALME\n";break;
			case 4:cout<<"FMALE\n";break;
		}

	}
} 
