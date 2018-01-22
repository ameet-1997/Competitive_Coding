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

// vll for_heap(100000);

int main()
{
	ll test;
	cin>>test;

	while(test--)
	{
		ll n,d;
		cin>>n>>d;

		vector< pair<ll, pair<ll,ll> > > info(n);
		rep(i,n)
		{	
			cin>>info[i].first;
			cin>>info[i].second.first;
			cin>>info[i].second.second;

			// for_heap[i].first = info[i].second.second;
			// for_heap[i].second.first = info[i].second.first;
			// for_heap[i].second.second = day_arrived;

		}

		sort(info.begin(), info.begin()+n);

		priority_queue< pll > max_sadness;

		ll counter = 0;
		ll reduce_sadness = 0;

		f(i,1,d+1)
		{
			while((info[counter].first <= i)&&(counter<n))
			{
				max_sadness.push(mp(info[counter].second.second, info[counter].second.first));
				counter++;
			}

			if(!max_sadness.empty())
			{	
				pii temp = max_sadness.top();
				reduce_sadness += temp.first;
				max_sadness.pop();
				if(temp.second != 1)
				{
					max_sadness.push(mp(temp.first, temp.second-1));
				}
			}

		}

		ll answer = 0;
		rep(i,n)
		{
			answer += (info[i].second.second)*(info[i].second.first);
		}

		// cout<<"Total initial sadness is : "<<answer<<"\n";
		answer -= reduce_sadness;

		cout<<answer<<"\n";

	}
} 
