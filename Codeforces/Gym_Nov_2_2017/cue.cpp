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
	vector<int> balls(7);
	fill(balls.begin(), balls.end(), 0);
	map<string, int> scores;

	scores.insert(mp("red",1));
	scores.insert(mp("yellow",2));
	scores.insert(mp("green",3));
	scores.insert(mp("brown",4));
	scores.insert(mp("blue",5));
	scores.insert(mp("pink",6));
	scores.insert(mp("black",7));

	rep(i,n){
		string temp;
		cin>>temp;
		balls[scores[temp]-1]++;
	}

	int max_index = 6;
	for(int i=6;i>=0;--i){
		if(balls[i] > 0){
			max_index = i;
			break;
		}
	}

	int final_score = 0;
	// cout<<"Max index is: "<<max_index<<endl;
	if(max_index == 0){
		final_score = 1;
	}
	else{
		for(int i=0;i<7;++i){
			final_score += (i+1)*balls[i];
		}

		final_score += (max_index+1)*balls[0];
	}

	cout<<final_score<<endl;
} 
