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

vector<ll> snakes(100000);
vector<ll> aux_snake(100000);

int main()
{
	ll test;
	cin>>test;

	while(test--)
	{
		ll n,a,b,l;
		cin>>n>>l>>a>>b;

		for(int i=0;i<n;++i)
		{
			cin>>snakes[i];
		}

		sort(snakes.begin(), snakes.begin()+n);
		for(int i=0;i<n;++i)
		{
			aux_snake[i] = snakes[i] - i*l;
		}

		sort(aux_snake.begin(),aux_snake.begin()+n);

		//cout<<"Aux array\n";

		// for(int i=0;i<n;++i)
		// {
		// 	cout<<aux_snake[i]<<" ";
		// }
		// cout<<"\n";

		ll answer = aux_snake[n/2];

		if(answer < a)
		{
			answer = a;
		}

		if(answer > (b-n*l))
		{
			answer = b - n*l;
		}

		//cout<<"The answer is : "<<answer<<"\n";

		// if(answer < a)
		// {
		// 	answer = *(lower_bound(aux_snake.begin(), aux_snake.begin()+n, a));
		// }

		// if(answer > (b-n*l))
		// {
		// 	answer = *(--upper_bound(aux_snake.begin(), aux_snake.begin()+n, b-n*l));
		// }

		ll final_answer = 0;
		for(int i=0;i<n;++i)
		{
			final_answer += abs(aux_snake[i]-answer);
		}

		cout<<final_answer<<endl;
	}
} 









// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i,n) for(auto i=0; i<(n); i++)
// #define mem(x,val) memset((x),(val),sizeof(x));
// #define rite(x) freopen(x,"w",stdout);
// #define read(x) freopen(x,"r",stdin);
// #define all(x) x.begin(),x.end()
// #define sz(x) ((int)x.size())
// #define sqr(x) ((x)*(x))
// #define pb push_back
// #define mp make_pair
// #define clr clear()
// #define inf (1<<30)
// #define ins insert
// #define xx first
// #define yy second
// #define eps 1e-9
// #define MOD 1000000007
// #define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
// typedef long long i64;
// typedef unsigned long long ui64;
// typedef string st;
// typedef vector<int> vi;
// typedef vector<st> vs;
// typedef map<int,int> mii;
// typedef map<st,int> msi;
// typedef set<int> si;
// typedef set<st> ss;
// typedef pair<int,int> pii;
// typedef vector<pii> vpii;
// #define mx 0
// i64 absv(i64 x)
// {
//     if(x>0)
//         return x;
//     else return -1*x;
// }

// vi snakex(1000000);
// vector<i64> modsnakex(1000000);

// int main()
// {
//     i64 mindis;
//     int a,b,n,t,l;
//     cin>>t;
//     while(t--)
//     {
//         mindis=0;
//         cin>>n>>l>>a>>b;
//         rep(i,n)
//         {
//             cin>>snakex[i];
//             if(snakex[i]>b-l)
//                 {
//                     mindis+=snakex[i]-(b-l);
//                     snakex[i]=b-l;
//                 }
//             else if(snakex[i]<a)
//             {
//                 mindis+=a-snakex[i];
//                 snakex[i]=a;
//             }    
//         }
//         rep(i,n)
//         {
//             modsnakex[i]=i64(snakex[i])-i64(i)*i64(l);
//         }
//         sort(modsnakex.begin(),modsnakex.begin()+n);
//         if(n>1)
//         {	
//         	i64 mindis_1 = mindis;
//         	if(n%2 == 0)
//         	{
// 	            i64 val=modsnakex[n/2];
// 	            if(val<i64(a))
// 	            val=a;
// 	            if(val>i64(b)-i64(n)*i64(l))
// 	            val=i64(b)-i64(n)*i64(l);
// 	            rep(i,n)
// 	            mindis_1+=absv(modsnakex[i]-val);
//         	}

// 	        i64 val=modsnakex[n/2-1];
//             if(val<i64(a))
//             val=a;
//             if(val>i64(b)-i64(n)*i64(l))
//             val=i64(b)-i64(n)*i64(l);
//             rep(i,n)
//             mindis+=absv(modsnakex[i]-val);
//         	mindis = min(mindis_1,mindis);

//         }

//         cout<<mindis<<endl;
        
//         // cout<<absv(100000000000)<<absv(-1000000000000);
//     }
//     return 0;
// }