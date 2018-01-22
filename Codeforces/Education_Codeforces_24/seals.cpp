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

int n,a,b;

int main()
{	
	bool validate(int x, int y, int z, int w);

	cin>>n>>a>>b;
	vii seals(n);

	rep(i,n)
	{
		cin>>seals[i].first>>seals[i].second;
	}
	int answer = 0;

	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{	
			int brx, bry, tlx, tly;

			//Normal Normal
			brx = seals[i].first;
			bry = seals[i].second;
			tlx = a - seals[j].first + 1;
			tly = b - seals[j].second + 1;
			if(validate(brx,bry,tlx,tly))
			{
				answer = max(answer, seals[i].first*seals[i].second + seals[j].first*seals[j].second);
			}

			//Flip Normal
			brx = seals[i].second;
			bry = seals[i].first;
			tlx = a - seals[j].first + 1;
			tly = b - seals[j].second + 1;
			if(validate(brx,bry,tlx,tly))
			{
				answer = max(answer, seals[i].first*seals[i].second + seals[j].first*seals[j].second);
			}

			//Flip Flip
			brx = seals[i].second;
			bry = seals[i].first;
			tlx = a - seals[j].second + 1;
			tly = b - seals[j].first + 1;
			if(validate(brx,bry,tlx,tly))
			{
				answer = max(answer, seals[i].first*seals[i].second + seals[j].first*seals[j].second);
			}

			//Normal Flip
			brx = seals[i].first;
			bry = seals[i].second;
			tlx = a - seals[j].second + 1;
			tly = b - seals[j].first + 1;
			if(validate(brx,bry,tlx,tly))
			{
				answer = max(answer, seals[i].first*seals[i].second + seals[j].first*seals[j].second);
			}
		}
	}

	cout<<answer<<"\n";
}

bool validate(int x, int y, int z, int w)
{
	if((x >=1)&&(x<=a)&&(y >=1)&&(y<=b)&&(z >=1)&&(z<=a)&&(w >=1)&&(w<=b))
	{
		if((z <= x)&&(w <= y))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}