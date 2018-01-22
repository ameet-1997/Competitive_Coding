#include <bits/stdc++.h>
using namespace std;
#define rep(i,number_of_snakes) for(auto i=0; i<(number_of_snakes); i++)
#define mem(x,answer) memset((x),(answer),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
#define MOD 1000000007
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define mx 0

vi input(100000);

int most_number_of_snakes(vector<i64> &c, int n, int k) {
    
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) 
    {
        int mid = (l + h) / 2;
        if ( k*(n-mid) - (c[n-1] - c[mid] + input[mid]) - (mid-1) <= 0 ) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int test,number_of_snakes,queries,index,res;
    cin>>test;
    
    vector<i64> cumulative_sum(100000);
    while(test--)
    {
        cin>>number_of_snakes>>queries;
        int answer=0;
        rep(i,number_of_snakes)
        {
            cin>>input[i];
        }
        sort(input.begin(), input.begin()+number_of_snakes);

        cumulative_sum[0]=input[0];
        rep(i,number_of_snakes-1)
        {
            cumulative_sum[i+1] = cumulative_sum[i] + input[i+1];
        }

        rep(j,queries)
        {	
        	int k;
            cin>>k;
            index = lower_bound(input.begin(), input.begin()+number_of_snakes, k) - input.begin();

            if(index == 0)
            {
            	answer=number_of_snakes;	
            }
            else
            {
	            res = most_number_of_snakes(cumulative_sum, index, k);
	            answer = number_of_snakes-(res);
            }
            cout<<answer<<endl;
        }
    }
    return 0;
}