#include <iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;
	
	char s[100010];
	
	for(int i=0;i<test;++i)
	{
		cin>>s;
		int count = 0;
		int flag = 0;
		
		for(int j=0;s[j] != '\0';++j)
		{
			if(s[j] == '<')
			{
				flag = 1;
			}
			else if(s[j] == '>')
			{
				if(flag == 1)
				{
					count++;
					flag = 0;
				}
			}
			else
			{
				flag = 0;
			}
		}
		
		cout<<count<<"\n";
	}
}
