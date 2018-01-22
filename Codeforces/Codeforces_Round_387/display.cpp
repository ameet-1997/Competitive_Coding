#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int answer;
	int answer_check;
	answer_check = sqrt(n);
	if(answer_check*answer_check == n)
	{
		cout<<answer_check<<" "<<answer_check<<"\n";
	}
	else if((answer_check+1)*(answer_check+1) == n)
	{
		cout<<(answer_check+1)<<" "<<(answer_check+1)<<"\n";
	}
	else
	{
		for(int i=answer_check+1;i<=n;++i)
		{
			if(n%i == 0)
			{
				cout<<n/i<<" "<<i<<"\n";
				break;
			}
		}
	}

} 
