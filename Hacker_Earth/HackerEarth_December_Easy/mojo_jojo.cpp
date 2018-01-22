#include <iostream>

using namespace std;

int main()
{
	long long test;

	cin>>test;

	for(long long zz=0;zz<test;++zz)
	{	
		long long n,x;
		cin>>n>>x;
		
		if((n<=2)||(x == 1))
		{
			cout<<"Mojo\n";
			continue;
		}
		

		long long number_of_avoids = 0;

		while(x>1)
		{
			x = x/2;
			number_of_avoids++;
		}

		number_of_avoids--;


		if(n%3 != 0)
		{	
			if(number_of_avoids%2 == 0)
			{
				cout<<"Mojo\n";	
			}
			else
			{
				cout<<"Jojo\n";
			}
			
		}
		else
		{
			if(number_of_avoids%2 == 0)
			{
				cout<<"Jojo\n";	
			}
			else
			{
				cout<<"Mojo\n";
			}
		}
	}

	


} 
