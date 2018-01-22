#include <iostream> 

using namespace std;

int main()
{
	int n,k;

	cin>>n>>k;

	char a[1000];

	cin>>a;

	int g,t;

	for(int i=0;a[i]!='\0';++i)
	{
		if(a[i] == 'G')
		{
			g = i;
		}
		else if(a[i] == 'T')
		{
			t = i;
		}
	}

	if((t-g)%k != 0)
	{
		cout<<"NO\n";
	}
	else
	{	
		int flag = 0;
		if(t > g)
		{
			int check = g;

			while(g!=t)
			{
				g = g+k;
				if(a[g] == '#')
				{
					flag = 1;
					break;
				}
			}
		}
		else
		{
			int check = g;

			while(g!=t)
			{
				g = g - k;
				if(a[g] == '#')
				{
					flag = 1;
					break;
				}
			}
		}

		if(flag == 1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
}
