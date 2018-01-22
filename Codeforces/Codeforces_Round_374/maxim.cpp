#include <iostream>

using namespace std;

int main()
{
	int n,k,x;

	cin>>n>>k>>x;
	int a[1000000];

	int number_of_negs=0,number_of_zeros=0;

	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i] < 0)
		{
			number_of_negs++;
		}
		else if(a[i] == 0)
		{
			number_of_zeros++;
		}
	}

	if(number_of_negs%2 != 0)
	{
		
	}



} 
