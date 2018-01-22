#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin>>n;
    
    vector<int> v(100000);
    
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    
    sort(v.begin(),v.begin()+n);
    
    for(int i=0;i<n;++i)
        {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
 
