/*
Given an array, calculate the number of elements less than a given element in less than n time
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> v(100000);

int main()
{
	int n;
	cin>>n;

	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}


	sort(v.begin(),v.begin()+n);
	
	int number_of_queries;
	cin>>number_of_queries;

	while(number_of_queries--)
	{
		int num;
		cin>>num;

		cout<<"Number of elements smaller than the given number are : "<<( lower_bound(v.begin(),v.begin()+n,num) - v.begin() )<<"\n";
	}
} 
