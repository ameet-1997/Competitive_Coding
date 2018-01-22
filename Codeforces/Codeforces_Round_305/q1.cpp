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
	string s;
	cin>>s;

	int n;
	cin>>n;

	bool flag = true;

	int len = s.length();
	if(len%n)
	{
		flag = false;
		cout<<"NO\n";
	}
	else
	{	
		for(int i=0;i<len;i += len/n)
		{
			string temp = s.substr(i, len/n);
			string temp_r = temp;

			// cout<<"Reverse and Normal strings are : "<<temp_r<<" "<<temp<<endl;
			reverse(temp.begin(), temp.end());
			if(temp != temp_r)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
} 


// #include <bits/stdc++.h>
// #include <ext/algorithm>
// #include <ext/numeric>

// using namespace std;
// using namespace __gnu_cxx;

// #define ALL(c) c.begin(), c.end()
// #define SZ(x) ((int)(x).size())
// #define PB push_back
// #define MP make_pair
// #define DB(a) cerr << #a << " = " << (a) << endl;
// #define OUT( a , n ) for( int J = 0; J < (n); J++ )cout<< (a)[J] << " \n"[J == (n) - 1 ]
// #define WAIT cout << flush , system("PAUSE");
// #define lowbit(x) ((x) & (-x))
// #define CONTAINS(a, x) ((a).find(x) != (a).end())
// #define endl '\n'


// typedef long long ll;
// typedef pair<int, int> pii;

// const int MAXN = 2000;
// char s[ MAXN ];
// int rad[ 2 * MAXN ];

// void Manacher()
// {
//    int size = strlen( s );
//    /* Manacher's Algorithm */

//    int i , j , k;

//     for ( i = j = 0; i < 2 * size - 1; i += k ) {

//       while ( i - j >= 0 && i + j + 1 < 2 * size &&
//               s[ ( i - j ) / 2 ] == s[ ( i + j + 1 ) / 2 ] )
//                 j++;

//       rad[i] = j;
//       for ( k = 1; k <= rad[i] && rad[ i - k ] != rad[i] - k; k++ )
//         rad[ i + k ] = min( rad[ i - k ], rad[i] - k );

//       j = max( j - k, 0 );
//     }
// }

// bool isPal(int i , int j ) 
// {
//     return rad[i + j] >= j - i + 1;
// }

// int k;

// int main()
// {
//     ios::sync_with_stdio( 0 );
//     cin.tie( 0 );
    
//     cin >> s;
//     int len = strlen(s);
    
//     Manacher();
//     cin >> k;
    
//     if(len % k != 0)
//     {
//         cout << "NO\n";
//         return 0;
//     }
    
    
    
//     int sz = len / k;
    
//     int ini = 0;
//     for( int i = 0; i < k; i++ )
//     {
//         //cout << ini << " " << ini + sz - 1 << endl;;
//         if( !isPal(ini , ini + sz - 1))
//         {
//             cout << "NO\n";
//             return 0;
//         }
//         ini += sz;  
//     }
    
//     cout << "YES\n";
//     return 0;
        
    
// }