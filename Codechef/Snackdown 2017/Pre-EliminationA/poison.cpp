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

vector< pair<int,int> > row_snakes(100001);
vector< pair<int,int> > col_snakes(100001);

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int n,k,m;
		cin>>n>>k>>m;
		// m is the number of snakes

		int row = 0, col = 0, removed = 0;

		for(int i=0;i<m;++i)
		{
			int h_x,h_y,t_x,t_y;
			cin>>h_x>>h_y>>t_x>>t_y;

			h_x--;
			h_y--;
			t_x--;
			t_y--;

			if((h_x == t_x)&&(h_y == t_y))
			{
				if((h_y >= (n-k)/2)&&(h_y <= (n+k)/2-1))
				{
					row_snakes[row] = mp(min(h_y,t_y), max(h_y,t_y));
					row++;
				}
				else if((h_x >= (n-k)/2)&&(h_x <= (n+k)/2-1))
				{
					col_snakes[col] = mp(min(h_x,t_x), max(h_x,t_x));
					col++;
				}
			}
			else if(h_x == t_x) 		// Row snake
			{
				if(((h_y >= (n-k)/2)&&(h_y <= (n+k)/2-1))||((t_y >= (n-k)/2)&&(t_y <= (n+k)/2-1))||((min(h_y,t_y) < (n-k)/2)&&(max(h_y,t_y) > (n+k)/2-1)))
				{
					row_snakes[row] = mp(min(h_y,t_y), max(h_y,t_y));
					row++;
				}
			}
			else if(h_y == t_y)
			{
				if(((h_x >= (n-k)/2)&&(h_x <= (n+k)/2-1))||((t_x >= (n-k)/2)&&(t_x <= (n+k)/2-1))||((min(h_x,t_x) < (n-k)/2)&&(max(h_x,t_x) > (n+k)/2-1)))
				{
					col_snakes[col] = mp(min(h_x,t_x), max(h_x,t_x));
					col++;
				}
			}
		}

		for(int i=0;i<row;++i)
		{
			if(row_snakes[i].first < (n-k)/2)
			{
				row_snakes[i].first = (n-k)/2;
			}
			if(row_snakes[i].second > (n+k)/2-1)
			{
				row_snakes[i].second = (n+k)/2-1;
			}
		}

		for(int i=0;i<col;++i)
		{
			if(col_snakes[i].first < (n-k)/2)
			{
				col_snakes[i].first = (n-k)/2;
			}
			if(col_snakes[i].second > (n+k)/2-1)
			{
				col_snakes[i].second = (n+k)/2-1;
			}
		}

		sort(row_snakes.begin(),row_snakes.begin()+row);
		sort(col_snakes.begin(),col_snakes.begin()+col);

		// cout<<"Here\n";

		// cout<<"Number of row and column snakes : "<<row<<" "<<col<<"\n";

		// for(int i=0;i<row;++i)
		// {
		// 	cout<<row_snakes[i].first<<" : "<<row_snakes[i].second<<"\n";
		// }

		// for(int i=0;i<col;++i)
		// {
		// 	cout<<col_snakes[i].first<<" : "<<col_snakes[i].second<<"\n";
		// }

		bool is_possible = true;
		int total_enough = 0;
		
		// For Rows
		int next_cell = (n-k)/2;
		int i=0;

		while(next_cell <= (n+k)/2-1)
		{
			priority_queue< pair<int,int> > max_interval;

			while((row_snakes[i].first <= next_cell)&&(i<row))
			{
				max_interval.push(mp(row_snakes[i].second,row_snakes[i].first));
				i++;
			}

			if(max_interval.empty())
			{
				is_possible = false;
				break;
			}

			pair<int,int> temp = max_interval.top();
			next_cell = temp.first+1;
			total_enough++;
		}


		// For columns
		next_cell = (n-k)/2;
		i=0;

		while(next_cell <= (n+k)/2-1)
		{
			priority_queue< pair<int,int> > max_interval;

			while((col_snakes[i].first <= next_cell)&&(i<col))
			{
				max_interval.push(mp(col_snakes[i].second,col_snakes[i].first));
				i++;
			}

			if(max_interval.empty())
			{
				is_possible = false;
				break;
			}

			pair<int,int> temp = max_interval.top();
			next_cell = temp.first+1;
			total_enough++;
		}

		if(is_possible)
		{
			cout<<total_enough<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}

	}
} 
