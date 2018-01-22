#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int solution(vector<int> &A, int B);
	int n;
	cin>>n;
	vector<int> A(n);
	
	for(int i=0;i<n;++i)
	{
		cin>>A[i];
	}
	
	int B;
	cin>>B;
	
	cout<<solution(A,B)<<"\n";
}


int solution(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int len = A.size();
    int index = -1;
    
    for(int i=0;i<len-1;++i)
    {
        if(A[i+1] < A[i])
        {
            index = i;
            break;
        }
    }
    
    cout<<index<<"\n";
    
    int answer;
    
    if(index == -1)
    {
        int temp = lower_bound(A.begin(), A.end(), B) - A.begin();
        if(temp == len)
        {
            answer = -1;
        }
        else if(A[temp] == B)
        {
            answer = temp;
        }
        else
        {
            answer = -1;
        }
    }
    else
    {
        int temp = lower_bound(A.begin(), A.begin()+index+1, B) - A.begin();
        //cout<<"Temp is : "<<temp<<"\n";
        if((temp == index+1)||(A[temp] != B))
        {   
            //cout<<"here\n";
            temp = lower_bound(A.begin()+index+1, A.end(), B) - A.begin();
            if(temp == len)
            {
                answer = -1;
            }
            else if(A[temp] == B)
            {
                answer = temp;
            }
            else
            {
                answer = -1;
            }
        }
        else
        {
            if(A[temp] == B)
            {
                answer = temp;
            }
            else
            {
                answer = -1;
            }
        }
    }
    
    return answer;
}

