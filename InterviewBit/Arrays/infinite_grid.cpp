#include <bits/stdc++.h>

using namespace std;

int main()
{	
	vector<int> wave(vector<int> &A);
	int n;
	cin>>n;
	
	vector<int> input;
	input.resize(n);
	for(int i=0;i<n;++i)
	{
		cin>>input[i];
	}
	
	vector<int> ans = wave(input);
	
	for(int i=0;i<n;++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}

vector<int> wave(vector<int> &A){
	sort(A.begin(),A.end());
    vector<int> answer;
    int len = A.size();
    answer.resize(len);
    
    int counter1 = 1,counter2 = 0;
    
    for(int i=0;i<len;++i)
    {   
        if((len%2 == 1)&&(i == (len-1)))
        {
            answer[i] = A[len-1];
        }
        else if(i%2 == 0)
        {
            answer[i] = A[counter1];
            counter1+=2;
        }
        else
        {
            answer[i] = A[counter2];
            counter2+=2;
        }
    }
    
    return answer;
}
