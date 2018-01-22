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
	int test;
	cin>>test;

	vector< vector<int> > graph(2);
	graph[0].resize(1000);
	graph[1].resize(1000);

	vector< vector<int> > graph1(2);
	graph1[0].resize(1000);
	graph1[1].resize(1000);


	while(test--)
	{
		int n;
		cin>>n;

		char color;

		int number_of_black = 0;

		int min_first = n;
		int min_second = n;

		for(int i=0;i<n;++i)
		{
			cin>>color;
			if(color == '#')
			{
				graph[0][i] = 0;
				graph1[0][i] = 0;
				number_of_black++;
				if(i < min_first)
				{
					min_first = i;
				}
			}
			else
			{
				graph[0][i] = 1;	
				graph1[0][i] = 1;
			}
		}

		for(int i=0;i<n;++i)
		{
			cin>>color;
			if(color == '#')
			{
				graph[1][i] = 0;
				graph1[1][i] = 0;
				number_of_black++;
				if(i < min_second)
				{
					min_second = i;
				}
			}
			else
			{
				graph[1][i] = 1;
				graph1[1][i] = 1;
			}
		}

		// for(int i=0;i<2;++i)
		// {
		// 	for(int j=0;j<n;++j)
		// 	{
		// 		cout<<graph[i][j];
		// 	}
		// 	cout<<"\n";
		// }

		bool is_possible = false;

		//cout<<"Number of black : "<<number_of_black<<"\n";

		//cout<<"Mins are : "<<min_first<<" : "<<min_second<<"\n";

		if(min_first <= min_second)
		{	
			//cout<<"here"<<"\n";
			int count_of_black = 0;
			int i=min_first;
			int pos = 0;

			count_of_black++;
			graph[pos][i] = 1;

			while(i<n)
			{
				if(graph[1-pos][i] == 0)
				{	
					graph[pos][i] = 1;
					pos = 1-pos;
					count_of_black++;
				}
				else
				{
					if(i == n-1)
					{
						break;
					}
					else
					{
						if(graph[pos][i+1] == 0)
						{	
							graph[pos][i] = 1;
							i++;
							count_of_black++;
						}
						else
						{
							break;
						}
					}
				}
			}

			//cout<<"Count of black : "<<count_of_black<<"\n";

			if(count_of_black == number_of_black)
			{
				is_possible = true;
			}
		}

		if(min_second <= min_first)
		{	
			//cout<<"here"<<"\n";
			int count_of_black = 0;
			int i=min_second;
			int pos = 1;

			count_of_black++;
			graph1[pos][i] = 1;

			while(i<n)
			{
				if(graph1[1-pos][i] == 0)
				{	
					//cout<<"In loop\n";
					graph1[pos][i] = 1;
					pos = 1-pos;
					count_of_black++;
				}
				else
				{
					if(i == n-1)
					{
						break;
					}
					else
					{
						if(graph1[pos][i+1] == 0)
						{	
							graph1[pos][i] = 1;
							i++;
							count_of_black++;
						}
						else
						{
							break;
						}
					}
				}
			}

			// cout<<"Count of Black : "<<count_of_black<<"\n";

			if(count_of_black == number_of_black)
			{
				is_possible = true;
			}
		}

		if(is_possible)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
} 
