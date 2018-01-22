#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int length;
	cin>>length;

	char s[5000];
	char answer[5000];

	cin>>s;


	if(length%2 == 1)
	{
		int median = length/2;

		int place = 0;
		int sign = 1;

		for(int i=0;i<length;++i)
		{
			answer[median+place*sign] = s[i];
			if(sign < 0)
			{
				sign = sign*-1;
			}
			else
			{
				place++;
				sign = sign*-1;
			}
		}
	}
	else
	{
		int left = length/2-1;
		int right = length/2;

		for(int i=0;i<length;++i)
		{
			if(i%2 == 0)
			{
				answer[left] = s[i];
				left--;
			}
			else
			{
				answer[right] = s[i];
				right++;
			}
		}
	}

	answer[length] = '\0';

	cout<<answer<<"\n";
} 
