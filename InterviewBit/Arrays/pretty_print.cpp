#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int A;
	cin>>A;
    int n = A;
    
    vector< vector<int> > answer;
    answer.resize(2*n-1);
    
    for(int i=0;i<2*n-1;++i)
    {
        answer[i].resize(2*n-1);
    }
    
    cout<<"here\n";
    
    for(int i=0;i<2*n-1;++i)
    {
       for(int j=0;j<2*n-1;++j)
       {
           int side, top;
           side = min(j+1,2*n-1-j);
           top = min(i+1,2*n-1-i);
           
           int final = min(side,top);
           
           answer[i][j] = n-final+1;
       }
    }

    for(int i=0;i<2*n-1;++i)
    {
    	for(int j=0;j<2*n-1;++j)
    	{
    		cout<<answer[i][j]<<" ";
    	}
    	cout<<"\n";
    }

} 
