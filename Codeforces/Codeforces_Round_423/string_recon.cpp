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

vii places(1000000);
vector<char> final_string(1000000);

int main()
{	
	// fill(is_filled.begin(), is_filled.end(), 0);
	fill(final_string.begin(), final_string.end(), 'a');
	int n;
	cin>>n;

	vector<string> names(n);
	vi lengths(n);
	int number_of_places = 0;

	rep(i,n)
	{
		cin>>names[i];
		lengths[i] = names[i].length();
		int number;
		cin>>number;

		rep(j,number)
		{
			int temp;
			cin>>temp;
			places[number_of_places] = mp(temp-1, i);
			number_of_places++;
		}
	}

	sort(places.begin(), places.begin()+number_of_places);

	int initial_index = 0;
	int till = 0;

	for(int i=0;i<number_of_places;++i)
	{	
		if(places[i].first >= initial_index)
		{
			initial_index = places[i].first;
			for(int j=initial_index;j<initial_index + lengths[places[i].second];++j)
			{
				final_string[j] = names[places[i].second][j- places[i].first];
				till = j;
			}
			initial_index = places[i].first + lengths[places[i].second];
		}
		else
		{
			if(initial_index >= places[i].first + lengths[places[i].second])
			{
				continue;
			}
			else
			{
				for(int j=initial_index;j<places[i].first + lengths[places[i].second];++j)
				{
					final_string[j] = names[places[i].second][j- places[i].first];
					till = j;
				}
				initial_index = places[i].first + lengths[places[i].second];
			}
		}
	}

	for(int i=0;i<=till;++i)
	{
		cout<<final_string[i];
	}
	cout<<"\n";
}