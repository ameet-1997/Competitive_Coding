
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >



ll calculate(ll h,ll e);
ll a[100300]={0};

int main(){
	ll t;
	cin>>t;

	for (ll i = 2; i*i< 1000*100+3; ++i)
	{
		if(a[i]==0)
		{

			for (ll j = i*i; j<1000*100+3; j+=i)
			{
				if(a[j]==0)
				a[j]=i;
			}
		}
	}



	while(t--){
		ll val=1;
		int i,n;
		cin>>n;
		ll b[100010],c[100010]={0};
		rep(i,n){
			cin>>b[i];
		}

		ll check=2;
		while(check==2){
			
			check=0;
			rep(i,n){
				if(b[i]!=1)
					check=2;
				if(a[b[i]]!=0){

					c[a[b[i]]]++;
					b[i]=b[i]/a[b[i]];
				}
				else
				{
					c[b[i]]++;
					b[i]=1;
					//cout<<"hii    ";
					//cout<<"hii"<<endl;
					fflush(stdout);

				}

			}
			//cout<<"byee";

			//cout<<" mod  "<<mod<<endl;
			rep(i,1000*100+8){
				//cout<<c[i]<<"  "<<i<<endl;
				if(c[i]!=0){
					
					ll ans=calculate(2,c[i]);
					//cout<<ans<<endl;
					ans=(ans-1);
					ans%=mod;
					val*=calculate(i,ans);
					//cout<<i<<"  "<<c[i]<<"  "<<val<<"   "<<"fsd"<<calculate(2,1)<<endl;
					//cout<<ans<<endl;
					val%=mod;
					c[i]=0;
				}
			}
			
			


		}

		cout<<val<<endl;

	}
}

ll calculate(ll e,ll h){
	//cout<<e <<"  meee "<<h<<endl;
	ll p=1;
	if(h%2==1)
		p*=e;
	p%=mod;
	while(h/2!=0){
		h=h/2;
		e=e*e;
		e%=mod;
		if(h%2==1)
			p*=e;
		p%=mod;

	}
	p%=mod;
	return p;

}