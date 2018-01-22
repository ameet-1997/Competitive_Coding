#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<long long> sieve(1000000,0);
vector<long long> primes(1000000);

void construct_sieve()
    {
    
    for(long long i=2;i<1000000;++i)
        {
        for(long long j=2;;++j)
            {
            if(i*j < 1000000)
                {
                sieve[i*j] = 1;    
            }
            else
                {
                break;
            }
            
        }
    }
}


int main()
    {
    
    construct_sieve();
    
    long long count = 0;
    for(long long i=2;i<1000000;++i)
        {
        if(sieve[i] == 0)
            {
            primes[count] = i;
            count++;
        }
    }
    
    long long test;
    cin>>test;
    
    while(test--)
        {
        long long n;
        cin>>n;
        vector<long long>::iterator it;
        it = upper_bound(primes.begin(),primes.begin()+count,n);
        
        long long answer = 0;
        vector<long long>::iterator it1 = primes.begin();
        
        while(it1 != it)
            {
            answer+=*it1;
            it1++;
        }
        
        cout<<answer<<"\n";
        
        
    }
}
