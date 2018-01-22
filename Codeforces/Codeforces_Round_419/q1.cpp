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
	vector< pair<int,int> > time;

	for(int i=0;i<24;++i)
	{	
		int temp = (i%10)*10+(i/10);
		if(temp < 60)
		{
			time.push_back(mp(i,temp));
		}
		
	}

	string s;
	cin>>s;

	int hours = (s[0]-'0')*10+(s[1]-'0');
	int palin_hours = (s[1]-'0')*10+(s[0]-'0');
	int minutes = (s[3]-'0')*10+(s[4]-'0');
	int palin_minutes = (s[4]-'0')*10+(s[3]-'0');

	pair<int,int> current_time = mp(hours,minutes);

	vector< pair<int,int> >::iterator it = lower_bound(time.begin(), time.end(), current_time);
	int answer;

	if(it != time.end())
	{
		pair<int,int> temp = *it;
		answer = (temp.first - current_time.first)*60 + (temp.second - current_time.second);
	}
	else
	{
		answer = 60 - current_time.second;
	}

	cout<<answer<<"\n";



} 

	// int answer;

	// if(hours%10 < 6)
	// {
	// 	if(palin_hours >= minutes)
	// 	{
	// 		answer = palin_hours - palin_minutes;
	// 	}
	// 	else
	// 	{

	// 	}
	// }