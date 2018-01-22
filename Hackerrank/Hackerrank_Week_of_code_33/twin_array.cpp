#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> numbers1(n);
	vector<int> numbers2(n);
	
	for(int i=0;i<n;++i)
	{
		cin>>numbers1[i];
	}
	
	for(int i=0;i<n;++i)
	{
		cin>>numbers2[i];
	}
	
	int min11,min12,min21,min22;
	int ind11,ind12,ind21,ind22;
	
	vector<int>::iterator it = min_element(numbers1.begin(), numbers1.end());
	min11 = *it;
	ind11 = it-numbers1.begin();
	numbers1[ind11] = 100000;
	it = min_element(numbers1.begin(), numbers1.end());
	ind12 = it-numbers1.begin();
	min12 = *(min_element(numbers1.begin(), numbers1.end()));
	
	it = min_element(numbers2.begin(), numbers2.end());
	min21 = *it;
	ind21 = it-numbers2.begin();
	numbers2[ind21] = 100000;
	it = min_element(numbers2.begin(), numbers2.end());
	ind22 = it-numbers2.begin();
	min22 = *(min_element(numbers2.begin(), numbers2.end()));
	
	if(ind11 == ind21)
	{
		cout<<min(min12+min21, min11+min22)<<"\n";
	}
	else
	{
		cout<<min11+min21<<"\n";
	}
	
}
