#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
    	string numbers;
    	cin>>numbers;
    	int n = numbers.length();
    	int cur = 0;
    	int count = 0;
	    while(cur < n)
	    {
	        if(numbers[cur] == 'D')
	        {
	            while((numbers[cur] == 'D')&&(cur < n))
	            {
	                cur++;
	            }
	            count++;
	        }
	        else
	        {
	        	cur++;
			}
	    }

    	cur = 0;
    	int count2 = 0;
	    while(cur < n)
	    {
	        if(numbers[cur] == 'U')
	        {
	            while((numbers[cur] == 'U')&&(cur < n))
	            {
	                cur++;
	            }
	            count2++;
	        }
	        else
	        {
	        	cur++;
			}
	    }

	    count = min(count, count2);



	    cout<<count<<"\n";
    }
}