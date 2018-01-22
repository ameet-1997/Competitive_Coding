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

vector< vi > graph(20);
vector< vi > times(20);

int main()
{	
	bool validate(int,int,int,int);
	int m,n;
	cin>>m>>n;

	rep(i,m)
	{
		graph[i].resize(n);
		times[i].resize(n);
	}

	int start_x, start_y;
	cin>>start_x>>start_y;
	start_x--;
	start_y--;

	rep(i,m)
	{
		rep(j,n)
		{
			char c;
			cin>>c;
			if(c == 'T')
			{
				graph[i][j] = 1;
			}
			else
			{
				graph[i][j] = 0;
			}
		}
	}

	queue< pii > q;
	q.push(mp(start_x, start_y));
	graph[start_x][start_y] = 0;
	q.push(mp(-1,-1));

	int time = 1;

	while(!q.empty())
	{
		pii temp = q.front();
		q.pop();
		if(temp.first == -1)
		{
			q.push(mp(-1,-1));
			if(q.front().first == -1)
			{
				break;
			}
			else
			{
				time++;
			}
			continue;
		}

		times[temp.first][temp.second] = time;

		graph[temp.first][temp.second] = 0;
		int cur_x = temp.first, cur_y = temp.second;
		int x,y;

		//E
		x = cur_x;y = cur_y+1;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}

		//NE
		x = cur_x-1;y = cur_y+1;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}

		//N
		x = cur_x-1;y = cur_y;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}

		//NW
		x = cur_x-1;y = cur_y-1;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}

		//W
		x = cur_x;y = cur_y-1;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}

		//SW
		x = cur_x+1;y = cur_y-1;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}

		//S
		x = cur_x+1;y = cur_y;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}

		//SE
		x = cur_x+1;y = cur_y+1;
		if(validate(x,y,m,n)&&(graph[x][y]))
		{
			q.push(mp(x,y));
			graph[x][y] = 0;
		}


	}

	cout<<time;

	// rep(i,m)
	// {
	// 	rep(j,n)
	// 	{
	// 		cout<<times[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
} 

bool validate(int a, int b, int m, int n)
{
	if(((a>=0)&&(a<m))&&((b>=0)&&(b<n)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
