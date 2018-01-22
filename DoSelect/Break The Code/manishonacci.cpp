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
	vi fibonacci(10000);
	fibonacci[0] = 1;
	fibonacci[1] = 2;
	int num1=1, num2=2;

	int current = num1+num2;
	int counter = 2;

	while(current <= 100000)
	{
		//fibonacci.insert(mp(current, counter));
		fibonacci[counter] = current;
		counter++;
		num1 = num2;
		num2 = current;
		current = num1+num2;
	}

	int n;
	cin>>n;
	vi numbers(n);

	rep(i,n)
	{
		cin>>numbers[i];
	}

	ll answer = 0;

	rep(i,n)
	{
		int index = lower_bound(fibonacci.begin(), fibonacci.begin()+counter, numbers[i]) - fibonacci.begin();
		if((index < n)&&(fibonacci[index] == numbers[i]))
		{
			answer += (index+1);
		}
	}

	cout<<answer<<endl;
}