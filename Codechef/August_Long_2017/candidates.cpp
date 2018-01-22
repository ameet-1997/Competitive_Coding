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
#define ff first
#define ss second

//std::ios::sync_with_stdio(false); 

int main()
{
	int test;
	cin>>test;

	while(test--)
	{	
		int n,m;
		cin>>n>>m;
		vector< vi > qual(n);
		vi minsalary(n);
		viii salary(m);
		rep(i,n)
		{
			qual[i].resize(m);
		}

		rep(i,n)
		{
			cin>>minsalary[i];
		}

		rep(i,m)
		{
			cin>>salary[i].first;
			cin>>salary[i].second.first;
			salary[i].second.second = i;
		}

		sort(salary.begin(), salary.end());
		char c = getchar();

		rep(i,n)
		{
			rep(j,m)
			{
				c = getchar();
				qual[i][j] = c - '0';
			}
			c = getchar();
		}

		ll total_salary = 0;
		ll number_of_candidates = 0;
		vector<bool> companies(m);

		rep(i,n)
		{
			fd(j,m-1,0)
			{
				if((salary[j].ff >= minsalary[i])&&(qual[i][salary[j].ss.ss] == 1)&&(salary[j].ss.ff > 0))
				{
					salary[j].ss.ff--;
					minsalary[i] = -1;
					total_salary += salary[j].ff;
					number_of_candidates++;
					companies[j] = true;
					break;
				}
			}
		}

		ll offers = 0;
		rep(i,m)
		{
			if(!companies[i])
			{
				offers++;
			}
		}

		cout<<number_of_candidates<<" "<<total_salary<<" "<<offers<<endl;
	}
} 
