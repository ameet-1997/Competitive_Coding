#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int pow(int,int,int);
	int x,n,d;
	cin>>x>>n>>d;

	cout<<pow(x,n,d)<<"\n";
}




int pow(int x, int n, int d) {
    
    if(x == 0)
    {
        return 0;
    }
    
    bool sign = false;
    if(x<0&&(n%2 == 1))
    {
        sign = !sign;
    }
    
    if(x<0)
    {
        x = -x;
    }
    
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        if(sign)
        {   
            int answer = x%d;
            return -answer+d;
        }
        return x%d;
    }
    else
    {
        if(n%2 == 0)
        {
            int answer = pow(x,n/2,d);
            if(sign)
            {	
            	answer = (answer*answer)%d;
                return -answer+d;
            }
            return (answer*answer)%d;
        }
        else
        {
            int answer = pow(x,n/2,d);
            if(sign)
            {	
            	answer = (((answer*answer)%d)*x)%d;
                return -answer+d;
            }
            return (((answer*answer)%d)*x)%d;
        }
    }
} 
