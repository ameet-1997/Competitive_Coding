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

vector< vi > square(100);

int main()
{	
	rep(i,100)
	{
		square[i].resize(100);
	}

	int n,m;
	cin>>n>>m;

	int left = m-1, right = 0, top = n-1, bottom = 0;
	bool flag = false;

	rep(i,n)
	{
		rep(j,m)
		{
			char c;
			cin>>c;
			switch(c)
			{
				case 'W':{
					square[i][j] = 0;
					break;
				}
				case 'B':{
					square[i][j] = 1;

					left = min(left, j);
					right = max(right, j);
					top = min(top, i);
					bottom = max(bottom, i);
					flag = true;
					break;
				}
			}
		}
	}

	if(!flag)
	{
		cout<<"1\n";
		return 0;
	}

	int total = 0;
	int side1, side2;
	side1 = right - left + 1;
	side2 = bottom - top + 1;

	// cout<<"Left, right, top, bottom : "<<left<<" "<<right<<" "<<top<<" "<<bottom<<"\n";


	for(int i=top;i<=bottom;++i)
	{
		for(int j=left;j<=right;++j)
		{
			if(square[i][j] == 0)
			{
				total++;
			}
		}
	}

	if(side1 == side2)
	{
		cout<<total<<"\n";
	}
	else if(side1 > side2)
	{
		if(side1 > n)
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<total+(side1 - side2)*side1<<"\n";
		}
	}
	else
	{
		if(side2 > m)
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<total+(side2 - side1)*side2<<"\n";
		}		
	}

	
} 
