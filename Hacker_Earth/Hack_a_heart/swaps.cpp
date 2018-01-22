#include <bits/stdc++.h>

using namespace std;

/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            x%=MOD;
        }
        y = (y*y);
        y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 
int main()
{    
    int test;
    cin>>test;
    const int modulo = 1000*1000*1000+7;

    while(test--)
    {
    	int n,k;
    	cin>>n>>k;

    	long long answer = 1;
    	answer = pow(2,k,modulo)%(modulo);
    	answer = (answer*(C(n,k,modulo)))%modulo;

    	cout<<answer<<"\n;
    }
} 
