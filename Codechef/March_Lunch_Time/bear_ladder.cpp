#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin>>q;

	while(q--)
	{
		int a,b;
		cin>>a>>b;

		int temp1, temp2;
		temp1 = max(a,b);
		temp2 = min(a,b);
		a = temp1;
		b = temp2;

		if(a%2 == 0)
		{
			if((a == (b+1))||(a == (b+2)))
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else
		{
			if(a == b+2)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}
}
