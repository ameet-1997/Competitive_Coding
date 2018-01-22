#include <bits/stdc++.h>
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

int main()
{
	int k,n;
	cin>>k>>n;

	vi judges(k);
	vi cumulative(k);
	vi polycarp(n);
	map<int,int> present;

	rep(i,k)
	{
		cin>>judges[i];
	}

	cumulative[0] = judges[0];

	f(i,1,k)
	{
		cumulative[i] = cumulative[i-1] + judges[i];
	}

	// rep(i,k)
	// {
	// 	cout<<cumulative[i]<<" ";
	// }
	// cout<<"\n";

	rep(i,k)
	{
		if(present.find(cumulative[i]) == present.end())
		{
			present[cumulative[i]] = 1;
		}
		else
		{
			present[cumulative[i]] += 1;
		}
	}

	// cout<<"Present size : "<<present.size()<<"\n";

	rep(i,n)
	{
		cin>>polycarp[i];
	}

	sort(polycarp.begin(), polycarp.end());
	sort(cumulative.begin(), cumulative.end());

	set<int> answers;

	for(int i=0;i<k;++i)
	{
		int temp_answer = polycarp[0] - cumulative[i];
		map<int,int> temp_present = present;

		bool flag = true;
		rep(j,n)
		{
			if(binary_search(cumulative.begin(), cumulative.end(), polycarp[j] - temp_answer))
			{
				temp_present[polycarp[j] - temp_answer] -= 1;
				if(temp_present[polycarp[j] - temp_answer] < 0)
				{
					flag = false;
					break;
				}
			}
			else
			{	
				flag = false;
				break;
			}
		}

		if(flag)
		{
			answers.insert(temp_answer);
		}
	}

	cout<<answers.size()<<"\n";
} 
