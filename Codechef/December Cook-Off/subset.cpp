#include <iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;

	for(int zz=0;zz<test;++zz)
	{
		int a[4];
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		int flag = 0;

		for(int i=0;i<4;++i)
		{
			if(a[i] == 0)
			{
				flag = 1;
				break;
			}
		}

		if(((a[0]+a[1]) == 0)||((a[0]+a[2]) == 0)||((a[0]+a[3]) == 0)||((a[1]+a[2]) == 0)||((a[1]+a[3]) == 0)||((a[2]+a[3]) == 0))
		{
			flag = 1;
		}

		int sum = a[0]+a[1]+a[2]+a[3];
		if(sum == 0)
		{
			flag = 1;
		}

		if(((sum-a[0]) == 0)||((sum-a[1]) == 0)||((sum-a[2]) == 0)||((sum-a[3]) == 0))
		{
			flag = 1;
		}

		if(flag == 1)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
} 
