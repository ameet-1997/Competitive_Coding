#include <iostream>
#include <algorithm>
#include <vector>
#define max_long_int 9223372036854775807

using namespace std;

vector< pair<long long int,long long int> > numbers;


int main()
{	
	long long int check = 1;

	numbers.push_back(make_pair(1,1));

	int temp;

	while((check < max_long_int)&&(check*2 > check))
	{
		check = check*2;
		numbers.push_back(make_pair(check,2));
		//two.push_back(check);
	}

	typeof(numbers.begin()) it = numbers.begin();

	while(it!=numbers.end())
	{
		check = 1;
		while((check < max_long_int)&&(check*3 > check))
		{
			check = check*3;
			numbers.push_back(make_pair(check,3));
		}

		it++;
	}

	it = numbers.begin();

	while(it!=numbers.end())
	{
		check = 1;
		while(check < max_long_int)
		{
			check = check*5;
			numbers.push_back(make_pair(check,5));
		}
		it++;
	}

	it = numbers.begin();

	while(it!=numbers.end())
	{
		check = 1;
		while(check < max_long_int)
		{
			check = check*7;
			numbers.push_back(make_pair(check,7));
		}
		it++;
	}

	it = numbers.begin();

	while(it!=numbers.end())
	{
		check = 1;
		while(check < max_long_int)
		{
			check = check*11;
			numbers.push_back(make_pair(check,11));
		}
		it++;
	}



	sort(numbers.begin(),numbers.end());

	cout<<numbers.size()<<"\n";

	int test;
	cin>>test;



	for(int zz=0;zz<test;++zz)
	{
		int a,k,n;
		cin>>a>>k>>n;

	}
} 

