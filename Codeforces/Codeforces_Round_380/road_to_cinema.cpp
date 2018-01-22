#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int gas_position[200000];


//vector pair<int,int>(200000);
int price[200000];
int capacity[200000];

int cars,gas,length,t;

int main()
{	
	int possible(int);

	cin>>cars>>gas>>length>>t;


	for(int i=0;i<cars;++i)
	{
		cin>>price[i]>>capacity[i];
	}

	for(int i=0;i<gas;++i)
	{
		cin>>gas_position[i];
	}

	sort(gas_position,gas_position+gas);


	int min_price = INT_MAX;

	for(int i=0;i<cars;++i)
	{	
		if(price[i] < min_price)
		{
			int check = possible(i);
			if(check == 1)
			{
				min_price = price[i];
			}	
		}
		
	}


	if(min_price == INT_MAX)
	{
		cout<<"-1"<<"\n";
	}
	else
	{
		cout<<min_price<<"\n";
	}


} 

int possible(int c)
{
	long long time = 0;

	if(gas_position[0] > capacity[c])
	{	
		return -1;
	}
	else if(gas_position[0] <= capacity[c]/2)
	{
		time = time + gas_position[0];
		if(time > t)
		{	
			return -1;
		}
	}
	else
	{
		time = time + 3*(gas_position[0]) - capacity[c];

		if(time > t)
		{	
			return -1;
		}
	}


	for(int i=1;i<gas;++i)
	{
		if(gas_position[i]-gas_position[i-1] > capacity[c])
		{	
			
			return -1;
		}
		else if(gas_position[i]-gas_position[i-1] <= capacity[c]/2)
		{
			time = time + (gas_position[i]-gas_position[i-1]);
			if(time > t)
			{	
				return -1;
			}
		}
		else
		{
			time = time + 3*(gas_position[i]-gas_position[i-1]) - capacity[c];

			if(time > t)
			{	
				return -1;
			}
		}

	}

	if(length-gas_position[gas-1] > capacity[c])
	{	
		return -1;
	}
	else if(length-gas_position[gas-1] <= capacity[c]/2)
	{
		time = time + length-gas_position[gas-1];
		if(time > t)
		{	
			return -1;
		}
	}
	else
	{
		time = time + 3*(length-gas_position[gas-1]) - capacity[c];

		if(time > t)
		{	
			return -1;
		}
	}

	return 1;
}
