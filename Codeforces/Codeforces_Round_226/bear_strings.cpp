#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;

	vector<int> present;
	cin>>s;

	int len = s.length();

	for(int i=0;i<=len-4;++i)
	{
		if((s[i] == 'b')&&(s[i+1] == 'e')&&(s[i+2] == 'a')&&(s[i+3] == 'r'))
		{
			present.push_back(i+3);
		}
	}

	// vector<int>::iterator it = present.begin();
	// while(it != present.end())
	// {
	// 	cout<<*it<<" ";
	// 	it++;
	// }
	// cout<<"\n";

	long long answer = 0;
	size_t end = present.size();

	// cout<<"Value of end is : "<<end<<endl;

	for(int i=0;i<len;++i)
	{
		int index = lower_bound(present.begin(), present.end(),i+3) - present.begin();
		// cout<<"The value of index is : "<<index<<endl;
		if(index < end)
		{
			answer += (len - present[index]);
		}
	}

	cout<<answer<<"\n";
} 
