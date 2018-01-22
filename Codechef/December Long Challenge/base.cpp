#include <iostream>
#include <math.h>

using namespace std;

int main()
{	
	int check(int,int,int);
	int test;

	cin>>test;

	for(int i=0;i<test;++i)
	{
		long long n;
		cin>>n;

		if(n == 0)
		{
			cout<<"0\n";
		}
		else if(n == 1)
		{
			cout<<"INFINITY\n";
		}
		else
		{
			long long answer = 0;

			for(int i=2;i<=41;++i)
			{
				double temp = pow(float(n),1.0/(i-1));
				if(temp < 1.9)
				{
					continue;
				}
				cout<<"The calculated power is : "<<temp<<"\n";
				int i1 = int(temp);
				int i2 = i1+1;
				int lhs,rhs;
				if(check(i2,i-1,n))
				{
					lhs = i2;
				}
				else
				{
					lhs = i1;
				}

				temp = pow((n+1)/2,1/(i-1));
				i1 = int(temp);
				i2 = i1+1;
				if(((n+1)%2 == 0)&&(check(i1,i-1,(n+1)/2)))
				{
					rhs = i1;
				}
				else
				{
					rhs = i2;
				}

				if(rhs >= lhs)
				{
					answer = answer + rhs - lhs + 1;
				}
			}

			cout<<answer<<"\n";

		}

		
	}

} 


int check(int num,int pow,int res)
{	
	long long calculate_power(long long int num,long long int pow);
	long long ans = 1;

	ans = calculate_power(num,pow);
	if(ans == res)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

long long calculate_power(long long int num,long long int pow)
{
	if(pow == 1)
	{
		return num;
	}
	else if(pow == 0)
	{
		return 1;
	}
	else if(pow%2)
	{	
		long long temp = calculate_power(num,pow/2);
		return temp*temp*num;
	}
	else
	{	
		long long temp = calculate_power(num,pow/2);
		return temp*temp;	
	}
}
