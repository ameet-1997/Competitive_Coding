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
	int n;
	cin>>n;

	vl temps(n);
	vl numbers(6);
	vl final(6);

	rep(i,n)
	{
		cin>>temps[i];
	}

	sort(temps.begin(), temps.end());
	rep(i,6)
	{
		numbers[i] = temps[n-i-1];
	}

	final[0] = numbers[5];
	final[5] = numbers[4];

	ll answer = 0;

	// rep(i,6)
	// {
	// 	cout<<numbers[i]<<" ";
	// }
	// cout<<endl;


	// 1
	{
		final[1] = numbers[3];
		final[4] = numbers[2];
		final[2] = numbers[1];
		final[3] = numbers[0];

		ll temp = (final[0]+4*final[1]+6*final[2]+4*final[3]+final[4]+final[5]*0)*(final[0]*0+1*final[1]+4*final[2]+6*final[3]+4*final[4]+final[5]*1);

		answer = max(answer, temp);

	}

	// rep(i,6)
	// {
	// 	cout<<final[i]<<" ";
	// }
	// cout<<endl;	

	// 2
	{
		final[1] = numbers[2];
		final[4] = numbers[3];
		final[2] = numbers[1];
		final[3] = numbers[0];

		ll temp = (final[0]+4*final[1]+6*final[2]+4*final[3]+final[4]+final[5]*0)*(final[0]*0+1*final[1]+4*final[2]+6*final[3]+4*final[4]+final[5]*1);

		answer = max(answer, temp);

	}

	// rep(i,6)
	// {
	// 	cout<<final[i]<<" ";
	// }
	// cout<<endl;

	// 3
	{
		final[1] = numbers[3];
		final[4] = numbers[2];
		final[2] = numbers[0];
		final[3] = numbers[1];

		ll temp = (final[0]+4*final[1]+6*final[2]+4*final[3]+final[4]+final[5]*0)*(final[0]*0+1*final[1]+4*final[2]+6*final[3]+4*final[4]+final[5]*1);

		answer = max(answer, temp);

	}

	// rep(i,6)
	// {
	// 	cout<<final[i]<<" ";
	// }
	// cout<<endl;

	// 4
	{
		final[1] = numbers[2];
		final[4] = numbers[3];
		final[2] = numbers[0];
		final[3] = numbers[1];

		ll temp = (final[0]+4*final[1]+6*final[2]+4*final[3]+final[4]+final[5]*0)*(final[0]*0+1*final[1]+4*final[2]+6*final[3]+4*final[4]+final[5]*1);

		answer = max(answer, temp);

	}

	// rep(i,6)
	// {
	// 	cout<<final[i]<<" ";
	// }
	// cout<<endl;

	cout<<answer<<endl;
} 
