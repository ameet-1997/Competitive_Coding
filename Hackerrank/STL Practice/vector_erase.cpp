#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
	vector<int> v(100000);

	int n;
	cin>>n;

	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}

	int number1,range_x,range_y;
	cin>>number1>>range_x>>range_y;

	int total=0;

	if(number1 < range_x)
	{
		v.erase(v.begin()+range_x-1,v.begin()+range_y-1);
		v.erase(v.begin()+number1-1);
		total = n-1-(range_y-range_x);
	}
	else if(number1 <= range_y)
	{	
		v.erase(v.begin()+range_x-1,v.begin()+range_y-1);
		total = n-(range_y-range_x);
	}
	else
	{
		v.erase(v.begin()+number1-1);
		v.erase(v.begin()+range_x-1,v.begin()+range_y-1);
		total = n-1-(range_y-range_x);
	}

	cout<<total<<"\n";
	for(int i=0;i<total;++i)
	{
		cout<<v[i]<<" ";
	}

	cout<<"\n";
}
