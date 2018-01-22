#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
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
i64 absv(i64 x)
{
    if(x>0)
        return x;
    else return -1*x;
}
int main()
{
    i64 mindis;
    int a,b,n,t,l;
    cin>>t;
    vi snakex;
    vector<i64> modsnakex;
    while(t--)
    {
        mindis=0;
        cin>>n>>l>>a>>b;
        snakex=vi(n);
        modsnakex=vector<i64>(n);
        rep(i,n)
        {
            cin>>snakex[i];
            if(snakex[i]>b-l)
                {
                    mindis+=snakex[i]-(b-l);
                    snakex[i]=b-l;
                }
            else if(snakex[i]<a)
            {
                mindis+=a-snakex[i];
                snakex[i]=a;
            }    
        }
        rep(i,n)
        {
            modsnakex[i]=i64(snakex[i])-i64(i)*i64(l);
        }
        sort(modsnakex.begin(),modsnakex.end());
        if(n>1)
        {
            i64 val=modsnakex[n/2];
            if(val<i64(a))
            val=a;
            if(val>i64(b)-i64(n)*i64(l))
            val=i64(b)-i64(n)*i64(l);
            rep(i,n)
            mindis+=absv(modsnakex[i]-val);
        }
        cout<<mindis<<endl;
        
        // cout<<absv(100000000000)<<absv(-1000000000000);
    }
    return 0;
} 