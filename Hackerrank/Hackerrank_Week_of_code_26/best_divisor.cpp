#include <iostream>

using namespace std;

int main()
{	
	int calculate_digit_sum(int);

	int n;

	cin>>n;

	int answer = 1;
	int temp;
	int number = 1;

	for(int i=2;i<=n;++i)
	{
		if(n%i == 0)
		{
			temp = calculate_digit_sum(i);
			if(temp > answer)
			{
				answer = temp;
				number = i;
			}

		}
	}

	cout<<number<<"\n";

}


int calculate_digit_sum(int a)
{
	int sum = 0;

	while(a > 0)
	{
		sum = sum + a%10;
		a = a/10;
	}

	return sum;
} 
