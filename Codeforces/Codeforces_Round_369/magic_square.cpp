#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
char c;
bool flag;
#define ll long long
inline void read(ll&a)
{a=0;do c=getchar();while(c!='-'&&(c<'0'||c>'9'));c=c=='-'?flag=true,getchar():c;while(c<='9'&&c>='0')a=(a<<3)+(a<<1)+c-'0',c=getchar();a=flag?flag=false,-a:a;}

inline ll Min(ll &a,ll b){return a>b?a=b:a;}
inline ll Max(ll &a,ll b){return a<b?a=b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll abs(ll a){return a>0?a:-a;}
ll sx,sy;

ll M[501][501];
ll n,m;

inline void Solve(ll S)
{
	ll O=0,Sum=0;
	for(ll i=1;i<=n;i++)
		O+=M[i][sy];
	M[sx][sy]=S-O;
	if(S-O<=0)goto WM;
	for(ll i=1;i<=n;i++)
	{
		Sum=0;
		for(ll j=1;j<=n;j++)
		Sum+=M[i][j];
		if(Sum==S)continue;
		else goto WM;
	}
	for(ll i=1;i<=n;i++)
	{
		Sum=0;
		for(ll j=1;j<=n;j++)
		 Sum+=M[j][i];
		if(Sum==S)continue;
		else goto WM;
	}
	Sum=0;
		for(ll j=1;j<=n;j++)
		 Sum+=M[j][j];
		if(Sum==S);
		else goto WM;
		Sum=0;
		for(ll j=1;j<=n;j++)
		 Sum+=M[n-j+1][j];
		if(Sum==S);
		else goto WM;

	printf("%I64d\n",M[sx][sy]);
	return;
	WM:puts("-1");return;
}

int main()
{
	read(n);
	ll Sum;
	if(n==1)
		return puts("1"),0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
		{
			read(M[i][j]);
			if(!M[i][j])sx=i,sy=j;
		}
	for(ll i=1;i<=n;i++)
	{
		Sum=0;
		for(ll j=1;j<=n;j++)
		if(!M[i][j])goto ED;
		else Sum+=M[i][j];
		if(Sum)return Solve(Sum),0;
		ED:;
	}
	for(ll i=1;i<=n;i++)
	{
	
		Sum=0;
		for(ll j=1;j<=n;j++)
		if(!M[j][i])goto ED2;
		else Sum+=M[i][j];
		if(Sum)return Solve(Sum),0;
		ED2:;
	}
	

}