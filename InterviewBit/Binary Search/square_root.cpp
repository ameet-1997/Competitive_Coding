#include <bits/stdc++.h>

using namespace std;

int main()
{ 	

	int A;
	cin>>A;
    int guess = A/2;
    int left = 2;
    int right = 46340;
    guess = (left+right)/2;
    
    if(A == 0)
    {
        cout<<0;
        return 0;
    }
    else if(A == 1)
    {
        cout<<1;
        return 0;
    }
    
    while(true)
    {
        if((guess*guess <= A)&&((guess+1)*(guess+1) > A))
        {
            cout<<guess;
            return 0;
        }
        else if(guess*guess > A)
        {
            right = guess-1;
            guess = (left+right)/2;
        }
        else
        {
            left = guess+1;
            guess = (left+right)/2;
        }
    }
}