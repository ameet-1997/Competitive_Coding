#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;++i)
    {
        cin>>numbers[i];
    }
    
    vector< pair<int,int> > segments;
    
    int cur = 0;
    int answer = 0;
    while(cur < n)
    {
        if(numbers[cur] == 1)
        {
            int start = cur;
            while((numbers[cur] == 1)&&(cur < n))
            {
                cur++;
            }
            int end = cur-1;
            answer = max(answer, end-start+1);
            segments.push_back(make_pair(start,end));
        }
        else
        {
        	cur++;
		}
    }
    
    int number_of_segments = segments.size();
    if(number_of_segments <= 1)
    {
    	cout<<answer<<"\n";
	}
	else if(number_of_segments == 2)
	{
		if(segments[0].second == (segments[1].first-2))
		{
			answer = segments[0].second - segments[0].first + 1 + segments[1].second - segments[1].first + 1;
		}
		else
		{
			answer++;
		}
		cout<<answer<<"\n";
	}
	else
	{
		for(int i=0;i<number_of_segments-1;++i)
		{
			if(segments[i].second == (segments[i+1].first-2))
			{
				answer = max(answer, segments[i].second - segments[i].first + 1 + segments[i+1].second - segments[i+1].first + 1 + 1);
			}
			else
			{
				answer = max(answer, segments[i].second - segments[i].first + 1);
			}
		}
		
		answer = max(answer, segments[number_of_segments-1].second - segments[number_of_segments-1].first + 1);
		cout<<answer<<"\n";
	}
}
