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

vector< vi > ground(20);
vector< vi > visited(20);
int n;

void initialize_visited(int n)
{
	rep(i,n)
	{
		fill(visited[i].begin(), visited[i].end(), 0);
	}
}

int main()
{	
	bool validate(int,int);
	pii get_next_index(int,int,int);
	int get_new_direction(int,int);
	cin>>n;

	rep(i,n)
	{
		ground[i].resize(n);
		visited[i].resize(n);
		fill(visited[i].begin(), visited[i].end(), 0);
	}

	int a_row, a_col, b_row, b_col;
	cin>>a_row>>a_col>>b_row>>b_col;

	rep(i,n)
	{
		rep(j,n)
		{
			cin>>ground[i][j];
		}
	}

	int count_answer = INT_MAX;
	int count_barrier = INT_MAX;
	bool answer_flag = false;

	{
		// For left side ball movement
		int count = 0, barrier = 0;
		int row = b_row, col = b_col;
		int direction = 1;
		bool flag = false;

		while(validate(row, col))
		{	
			visited[row][col]++;
			if(visited[row][col] > 4)
			{
				break;
			}
			if((row == a_row)&&(col == a_col))
			{	
				flag = true;
				break;
			}
			count++;

			if(ground[row][col])
			{	
				barrier++;
				direction = get_new_direction(direction, ground[row][col]);
			}
			pii temp = get_next_index(row, col, direction);
			row = temp.first;
			col = temp.second;
		}

		answer_flag = answer_flag || flag;
		if(flag)
		{
			if(mp(count_answer, count_barrier) > mp(count, barrier))
			{
				count_answer = count;
				count_barrier = barrier;
			}
		}
	}

	initialize_visited(n);


	{
		// For right side ball movement
		int count = 0, barrier = 0;
		int row = b_row, col = b_col;
		int direction = 2;
		bool flag = false;

		while(validate(row, col))
		{	
			visited[row][col]++;
			if(visited[row][col] > 4)
			{
				break;
			}
			if((row == a_row)&&(col == a_col))
			{	
				flag = true;
				break;
			}
			count++;

			if(ground[row][col])
			{	
				barrier++;
				direction = get_new_direction(direction, ground[row][col]);
			}
			pii temp = get_next_index(row, col, direction);
			row = temp.first;
			col = temp.second;
		}

		answer_flag = answer_flag || flag;
		if(flag)
		{
			if(mp(count_answer, count_barrier) > mp(count, barrier))
			{
				count_answer = count;
				count_barrier = barrier;
			}
		}
	}

	initialize_visited(n);


	{
		// For up ball movement
		int count = 0, barrier = 0;
		int row = b_row, col = b_col;
		int direction = 3;
		bool flag = false;

		while(validate(row, col))
		{	
			visited[row][col]++;
			if(visited[row][col] > 4)
			{
				break;
			}
			if((row == a_row)&&(col == a_col))
			{	
				flag = true;
				break;
			}
			count++;

			if(ground[row][col])
			{	
				barrier++;
				direction = get_new_direction(direction, ground[row][col]);
			}
			pii temp = get_next_index(row, col, direction);
			row = temp.first;
			col = temp.second;
		}

		answer_flag = answer_flag || flag;
		if(flag)
		{
			if(mp(count_answer, count_barrier) > mp(count, barrier))
			{
				count_answer = count;
				count_barrier = barrier;
			}
		}
	}

	initialize_visited(n);

	{
		// For down ball movement
		int count = 0, barrier = 0;
		int row = b_row, col = b_col;
		int direction = 4;
		bool flag = false;

		while(validate(row, col))
		{	
			visited[row][col]++;
			if(visited[row][col] > 4)
			{
				break;
			}
			if((row == a_row)&&(col == a_col))
			{	
				flag = true;
				break;
			}
			count++;

			if(ground[row][col])
			{	
				barrier++;
				direction = get_new_direction(direction, ground[row][col]);
			}
			pii temp = get_next_index(row, col, direction);
			row = temp.first;
			col = temp.second;
		}

		answer_flag = answer_flag || flag;
		if(flag)
		{
			if(mp(count_answer, count_barrier) > mp(count, barrier))
			{
				count_answer = count;
				count_barrier = barrier;
			}
		}
	}

	if(answer_flag)
	{
		cout<<count_answer<<" "<<count_barrier<<"\n";
	}
	else
	{
		cout<<"-1\n";
	}
} 

int get_new_direction(int direction, int barrier)
{
	if(barrier == 1)
	{
		switch(direction)
		{
			case 1:{
				return 4;
				break;
			}
			case 2:{
				return 3;
				break;
			}
			case 3:{
				return 2;
				break;
			}
			case 4:{
				return 1;
				break;
			}
		}
	}
	else
	{
		switch(direction)
		{
			case 1:{
				return 3;
				break;
			}
			case 2:{
				return 4;
				break;
			}
			case 3:{
				return 1;
				break;
			}
			case 4:{
				return 2;
				break;
			}
		}		
	}
}

pii get_next_index(int row,int col,int direction)
{
	pii temp;
	switch(direction)
	{
		case 1:{
			temp.first = row;
			temp.second = col-1;
			break;
		}
		case 2:{
			temp.first = row;
			temp.second = col+1;
			break;
		}
		case 3:{
			temp.first = row-1;
			temp.second = col;
			break;
		}
		case 4:{
			temp.first = row+1;
			temp.second = col;
			break;
		}
	}
	return temp;
}

bool validate(int a, int b)
{
	if(((a>=0)&&(a<n))&&((b>=0)&&(b<n)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
