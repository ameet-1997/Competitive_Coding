#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prlong longs 64
//setfilong long -   cout << setfilong long ('x') << setw (5); cout << 77 << endl; prlong longs xxx77
//setprecision - cout << setprecision (4) << f << endl; Prlong longs x.xxxx

using namespace std;


//std::ios::sync_with_stdio(false); 

int main()
{
	long long n;
	cin>>n;

	set<long long> numbers;

	for(int i=0;i<n;++i)
	{
		long long temp;
		cin>>temp;
		numbers.insert(temp);
	}

	long long len = numbers.size();

	vector<long long> num(numbers.begin(), numbers.end());

	if((len == 1)||(len == 2))
	{
		cout<<"YES\n";
	}
	else if(len == 3)
	{
		if(num[0]%2 == num[2]%2)
		{
			if(num[1] == (num[0] + num[2])/2)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else
		{
			cout<<"NO\n";
		}	
	}
	else
	{
		cout<<"NO\n";
	}
} 
